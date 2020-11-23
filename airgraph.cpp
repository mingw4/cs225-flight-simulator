#include <fstream>
#include "airgraph.h"
#include <iostream>

using std::ios;
using std::ifstream;

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
		while(getline(airports, x)) {
			vector<string> sv = split(x, ',');
			if (sv[6] == "Y") continue; //if code share continue
			Vertex source = vertice[sv[1]];
			Vertex dest = vertice[sv[3]];
			double w = 0; //calculateWeight()
			g.insertEdge(source,dest,w,sv[8],std::stoi(sv[7]));
		}	
	}
	
}

Graph& AirGraph::getGraph() {
	return g;
}
