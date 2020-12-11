
#include "airgraph.h"
#include "traversalUtil.h"
using std::cout;
using std::endl;

int main() {
	AirGraph a("./autoport.dat.txt", "./autoroute.dat.txt");
	Graph g = a.getGraph();
	traversal t;
	vector<Vertex> vv;
	t.bfs(vv, g, Vertex("0001"));
	if (vv.size() != 100) return -1;
	int level = 0;
	for (Vertex & v : vv) {
		int curr = std::stoi(v.getid()) / 1000;
		if ( curr > level) {
			level = curr;
		}
		if (level < curr) {
			cout << "bfs error:" << "source: 0001" << endl;
			cout << v.getid() << "after level: " << level;
		}
	}
	vv.clear();
	AirGraph a1("./autoport.dat.txt", "./traversal_test_route.dat.txt");
	a1.getGraph().showStats();
	for (int i = 0; i < 8; i++) {
		t.bfs(vv, a1.getGraph(), Vertex("000" + std::to_string(i)));
		if ((int) vv.size() != (8 - i)) {
			cout << i << ": " << vv.size() <<endl;
				return -1; 
		}
		vv.clear();
	}
	g.showStats();
	return 0;
}
