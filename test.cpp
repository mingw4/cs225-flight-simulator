
#include "airgraph.h"



int main() {
	AirGraph a("./testa.dat.txt", "./testr.dat.txt");
	Graph g = a.getGraph();
	g.showStats();
	return 0;
}
