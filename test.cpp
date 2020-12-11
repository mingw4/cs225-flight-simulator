
#include "airgraph.h"
#include "LandmarkPath.h"
#include <iostream>
using namespace std;
#include <vector>


int main() {
	cout << "Dijkstra test 1" << endl;
	AirGraph a1("./autoport.dat.txt", "./Dijkstra_testsimple_route.dat.txt");
	Vertex source1("0000", 0.0, 0.0, "TOO");
	Dijkstra d1(a1, source1);
	Vertex dest1("0004", 40.0, 0.0, "T04");
	vector<Edge> ans1 = d1.shortestPathTo(dest1);
	for (unsigned i = 0; i < ans1.size(); i++) {
		cout << "from " << ans1[i].source.getiata() << " to " << ans1[i].dest.getiata() << endl;
	}
	// expected answer: "T00" - "T02" - "T04"

	cout << "Dijkstra test 2" << endl;
	AirGraph a2("./autoport.dat.txt", "./Dijkstra_testcomplex1_route.dat.txt");
	Vertex source2("0000", 0.0, 0.0, "TOO");
	Dijkstra d2(a2, source2);
	Vertex dest2("1005", 50.0, 10.0, "T15");
	vector<Edge> ans2 = d2.shortestPathTo(dest2);
	for (unsigned i = 0; i < ans2.size(); i++) {
		cout << "from " << ans2[i].source.getiata() << " to " << ans2[i].dest.getiata() << endl;
	}
	// expected answer: "T00" - "T13" - "T15"

	cout << "Dijkstra test 3" << endl;
	AirGraph a3("./autoport.dat.txt", "./Dijkstra_testcomplex2_route.dat.txt");
	Vertex source3("1006", 60.0, 10.0, "T16");
	Dijkstra d3(a3, source3);
	Vertex dest3("1005", 50.0, 10.0, "T15");
	vector<Edge> ans3 = d3.shortestPathTo(dest3);
	for (unsigned i = 0; i < ans3.size(); i++) {
		cout << "from " << ans3[i].source.getiata() << " to " << ans3[i].dest.getiata() << endl;
	}
	// expected answer: "T16" - "T13" - "T15"

	cout << "Landmark test 1" << endl;
	AirGraph b1("./autoport.dat.txt", "./Landmark_test1_route_dat.txt");
	LandmarkPath l1(b1);
	vector<Edge> result1;
	Vertex source_1("0000", 0.0, 0.0, "TOO");
	Vertex dest_1("1005", 50.0, 10.0, "T15");
	Vertex landmark_1("0002", 20.0, 0.0, "T02");
	vector<Vertex> path1;
	path1.push_back(landmark_1);
	l1.find(result1, source_1, dest_1, path1);
	cout << result1.size() << endl;
	for (unsigned i = 0; i < result1.size(); i++) {
		cout << "from " << result1[i].source.getiata() << " to " << result1[i].dest.getiata() << endl;
	}
	// Graph g = a.getGraph();
	// g.showStats();


	return 0;
}
