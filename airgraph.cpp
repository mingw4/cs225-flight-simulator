#include <fstream>
#include "airgraph.h"
#include <iostream>
#include <map>
#include <iterator>
#include<cmath>

using std::ios;
using std::ifstream;

//Dis calculation according to lat & lng
double getDistance(Vertex n1, Vertex n2)
{	

	const double t = 0.017453292519943295;
    double longitude1=n1.getLongtitude(), latitude1=n1.getLatitude(), longitude2=n2.getLongtitude(), latitude2=n2.getLatitude();
    //lat
	
    //difference of lat /rad
	
	double lat1 = latitude1 * t;
	double lat2 = latitude2 * t;
    double  a = lat1 - lat2;
    //difference of lng /rad
    double  b = (longitude1 - longitude2) * t;
    //calgulate the distance
	
	double s = 0.5 - cos(a)/2 + cos(lat1) * cos(lat2) * (1-cos(b))/2;
    //double s = 2*asin(sqrt(pow(sin(a/2),2)+cos(lat1)*cos(lat2)*pow(sin(b/2),2)));
    //s = s * 6371;//the radius of earth (km)
	
    return 12742 * asin(sqrt(s));
}


vector<string> AirGraph::split(string s, char sep) {
	vector<string> ret;
	size_t pos = 0;
	bool quotation = false;
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == '"') quotation = !quotation;
		if (quotation) continue;
		if (s[i] == sep) {
			ret.push_back(s.substr(pos, i - pos));
			pos = i + 1;
		}

	}
	ret.push_back(s.substr(pos, s.size() - pos));
	return ret;
}


AirGraph::AirGraph(): g() {
	ifstream airports("./airports.dat.txt", ios::in);
	if (airports.is_open()) {
		string x;
		while(getline(airports, x)) {
			vector<string> sv = split(x, ',');
			/**sv index table:  0 - airport_id
			  					1 , 2 ,3 - name, city, country
								4 , 5 - IATA, ICAO
								6, 7  - Lat, Lnt
								nvm
			*/
			Vertex v(sv[0], std::stod(sv[6]), std::stod(sv[7]));
			g.insertVertex(v);
			vertice[sv[0]] = v;
		}
	}
	
	ifstream routes("./routes.dat.txt", ios::in);
	if (routes.is_open()) {
		string x;
		while(getline(routes, x)) {
			vector<string> sv = split(x, ',');
			if (sv[6] == "Y") continue; //if code share continue


			Vertex source = vertice[sv[3]];
			
			Vertex dest = vertice[sv[5]];
			//std::cout << "from id " << sv[3] << " to id " << sv[5] << std::endl;
			//distance based weight
			double w = getDistance(source, dest);
			//calculate cruise time
			w /= 850;
			w += 2;
			// add stop time if needed
			if (std::stoi(sv[7]) > 0) w+=2;

			std::cout << "from id " << sv[3] << " to id " << sv[5] << std::endl;
			std::cout << "estimated travel time:" << w <<std::endl;

			g.insertEdge(source,dest,w,sv[8],std::stoi(sv[7]));
		}	
	}
	
}

Graph& AirGraph::getGraph() {
	return g;
}
