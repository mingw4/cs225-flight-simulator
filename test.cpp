
#include "airgraph.h"



int main() {
	AirGraph a("autoport.dat.txt", "./autoroute.dat.txt");
	Graph g = a.getGraph();
	g.showStats();
	return 0;
}
