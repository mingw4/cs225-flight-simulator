#include <fstream>
#include "airgraph.h"
#include <iostream>
#include <map>
#include <iterator>
#include<cmath>

using std::ios;
using std::ifstream;

double toRadians(double angdeg)
{
    double E = 2.7182818284590452354;
    double PI = 3.14159265358979323846;
    return angdeg / 180.0 * PI;
}
//Dis calculation according to lat & lng
double getDistance(Vertex n1, Vertex n2)
{
    double longitude1=n1.getLongtitude(), latitude1=n1.getLatitude(), longitude2=n2.getLongtitude(), latitude2=n2.getLatitude();
    //lat
    double  lat1 = toRadians(latitude1);
    double  lat2 = toRadians(latitude2);
    //lng
    double  lng1 = toRadians(longitude1);
    double  lng2 = toRadians(longitude2);
    //difference of lat
    double  a = lat1 - lat2;
    //difference of lng
    double  b = lng1 - lng2;
    //calgulate the distance
    double s = 2*asin(sqrt(pow(sin(a/2),2)+cos(lat1)*cos(lat2)*pow(sin(b/2),2)));
    s = s * 6371;//the radius of earth (km)
    return s;
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
			double w = getDistance(source, dest);


			g.insertEdge(source,dest,w,sv[8],std::stoi(sv[7]));
		}	
	}
	
}

Graph& AirGraph::getGraph() {
	return g;
}
