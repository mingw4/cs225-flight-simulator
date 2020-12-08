//@author:: Bohan Liu


#include "airgraph.h"
#include <iostream>
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
					start = "\"" + argv[i + 1] "\"";
				}
				if (x == "-to") {
					end = "\"" + argv[i + 1] "\"";
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
		cout << "Airport not in data or malformed airport entry: " << s << endl;
		return -1;
	}
	Graph g = a.getGraph();

	g.showStats();
	return 0;
}
