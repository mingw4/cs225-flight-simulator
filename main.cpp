//@author:: Bohan Liu


#include "airgraph.h"

int main() {
	string port = "./airports.dat.txt";
	string routes = "./routes.dat.txt";
	AirGraph a = AirGraph(port, routes);

	Graph g = a.getGraph();
	g.showStats();
	return 0;
}
