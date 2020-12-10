// @author: 


#include <iostream>
#include "LandmarkPath.h"
using std::cout;
using std::endl;



int main(int argc,  char* argv[]) {
	unordered_map<string, string> flagv;
	unordered_map<string, bool> boolv;
	string ports = "./airports.dat.txt";
	string routes = "./routes.dat.txt";
	string start = "\"PEK\"";
	string end = "\"JFK\"";
	for (int i = 1; i < argc; i++) {
		string x = argv[i];
		if (argv[i][0] == '-') {
			if (i < argc - 1) {
				if (argv[i+1][0] == '-') {
					cout << "Bad argument for flag: " << argv[i] << ". value required!"<< endl;
					return -1;
				}	
				if (x == "-LFports") {
					ports = argv[i + 1];
				}
				if (x == "-LFroutes") {
					routes = argv[i + 1];
				}
				if (x == "-from") {
					start = argv[i + 1];
					start = "\"" + start + "\"";
				}
				if (x == "-to") {
					end =  argv[i + 1];
					end = "\"" + end + "\"";
				}
			} else {
				cout << "Bad argument for flag: " << argv[i] << ". value required!"<< endl; 
				return -1;
			}
		}
	}
	AirGraph a;
	try {
		a = AirGraph(ports, routes);
	} catch (string s){
		cout << "Bad Path: " << s << "!" << endl;
		return -1;
	}
	
	try {
		start = a.getid(start);
		end = a.getid(end);
	} catch (string s)	{
		cout << "Airport not in data or malformatted airport entry: " << s << endl;
		return -1;
	}
	Vertex source;
	Vertex dest;
	try {
		source  = a.getVertex(start);
		dest = a.getVertex(end);
	} catch(string s) {
		cout << "Malformatted entry:missing id / IATA / lat / lng" + s << endl;
		return -1;
	}


	Dijkstra d(a, source);
	vector<Edge> ev = d.shortestPathTo(dest);
	for (Edge &e : ev) {
		cout << e.source.getiata() <<endl;
	}
	return 0;
}
