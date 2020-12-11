#include "airgraph.h"
#include "LandmarkPath.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include "traversalUtil.h"

int distance(Vertex& a, Vertex& b) {
	double a1 = a.getLatitude();
	double a2 = a.getLongtitude();	
	double b1 = b.getLatitude();
	double b2 = b.getLongtitude();
	
	return ((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2)) / 100;

}

void buildGraph(Graph& g, string p, string r) {
	AirGraph a;
	unordered_map<string,Vertex> vertice;
	ifstream ver(p, ios::in);
	if (ver.is_open()) {
        string x;
        while(getline(ver,  x)) {
            vector<string> sv = a.split(x, ',');
            double lat, lnt;
            try {
                lat = std::stod(sv[6]);
                lnt = std::stod(sv[7]);
            } catch (std::invalid_argument) {
                cout << sv[6] << sv[7] << endl;
                continue;
            }

            /**sv index table:  0 - airport_id
                                1 , 2 ,3 - name, city, country
                                4 , 5 - IATA, ICAO
                                6, 7  - Lat, Lnt
                                nvm
            */
            Vertex v(sv[0], lat, lnt, sv[4]);
            g.insertVertex(v);
			vertice[sv[0]] = v;
        }
    }
	std::ifstream edges(r, ios::in);
    if (edges.is_open()) {
        string x;
        while(getline(edges, x)) {
            vector<string> sv = a.split(x, ',');
            int stops;
            try {
                std::stoi(sv[3]); std::stoi(sv[5]); //test if id is valid int form, though we use them as string

                stops = std::stoi(sv[7]);
            } catch (std::invalid_argument) {
                //skip if the structure isn't good.
                continue;
            }
            if (sv[6] == "Y") continue; //if code share continue
            Vertex source = vertice[sv[3]];
            Vertex dest = vertice[sv[5]];
            //std::cout << "from id " << sv[3] << " to id " << sv[5] << std::endl;
            //distance based weight
            double w = distance(source, dest);
            //std::cout << "from id " << sv[3] << " to id " << sv[5] << std::endl;
            //std::cout << "estimated travel time:" << w <<std::endl;
            g.insertEdge(source,dest,w, sv[0] + "--" + sv[8],stops);
        }
    }

}

int main() {
	// bfs test case
	AirGraph a("./autoport.dat.txt", "./autoroute.dat.txt");
	Graph g = a.getGraph();
	traversal t;
	vector<Vertex> vv;
	t.bfs(vv, g, Vertex("0001"));
	if (vv.size() != 100) return -1;
	int level = 0;
	for (Vertex & v : vv) {
		// cout<<"Test 1" << endl;
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



	cout << "Dijkstra test 1" << endl;
	Graph g1;
	buildGraph(g1, "./autoport.dat.txt", "./Dijkstra_testsimple_route.dat.txt");
//	AirGraph a1("./autoport.dat.txt", "./Dijkstra_testsimple_route.dat.txt");
	Vertex source1("0000", 0.0, 0.0, "TOO");
	Dijkstra d1(g1, source1);
	Vertex dest1("0004", 40.0, 0.0, "T04");
	vector<Edge> ans1 = d1.shortestPathTo(dest1);
	for (unsigned i = 0; i < ans1.size(); i++) {
		cout << "from " << ans1[i].source.getiata() << " to " << ans1[i].dest.getiata() << endl;
	}
	// expected answer: "T00" - "T02" - "T04"
	Graph g2;
	buildGraph(g2, "./autoport.dat.txt", "./Dijkstra_testcomplex1_route.dat.txt");
	cout << "Dijkstra test 2" << endl;
	Vertex source2("0000", 0.0, 0.0, "TOO");
	Dijkstra d2(g2, source2);
	Vertex dest2("1005", 50.0, 10.0, "T15");
	vector<Edge> ans2 = d2.shortestPathTo(dest2);
	for (unsigned i = 0; i < ans2.size(); i++) {
		cout << "from " << ans2[i].source.getiata() << " to " << ans2[i].dest.getiata() << endl;
	}
	// expected answer: "T00" - "T13" - "T15"

	cout << "Dijkstra test 3" << endl;
	Graph g3;
	buildGraph(g3, "./autoport.dat.txt", "./Dijkstra_testcomplex2_route.dat.txt");
	Vertex source3("1006", 60.0, 10.0, "T16");
	Dijkstra d3(g3, source3);
	Vertex dest3("1005", 50.0, 10.0, "T15");
	vector<Edge> ans3 = d3.shortestPathTo(dest3);
	for (unsigned i = 0; i < ans3.size(); i++) {
		cout << "from " << ans3[i].source.getiata() << " to " << ans3[i].dest.getiata() << endl;
	}
	// expected answer: "T16" - "T05" - "T07" - "T06" - "T15"


	Graph g4;
	buildGraph(g4, "./autoport.dat.txt", "./Landmark_test1_route_dat.txt");
	cout << "Landmark test 1" << endl;
	AirGraph b1("./autoport.dat.txt", "./Landmark_test1_route_dat.txt");
	b1.setG(g4);
	LandmarkPath l1(b1);
	vector<Edge> result1;
	Vertex source_1("0000", 0.0, 0.0, "TOO");
	Vertex dest_1("1005", 50.0, 10.0, "T15");
	Vertex landmark_1("0002", 20.0, 0.0, "T02");
	vector<Vertex> path1;
	path1.push_back(landmark_1);
	l1.find(result1, source_1, dest_1, path1);
	for (unsigned i = 0; i < result1.size(); i++) {
		cout << "from " << result1[i].source.getiata() << " to " << result1[i].dest.getiata() << endl;
	}
	// 00 - 05 - 02

	cout << "Landmark test 2" << endl;
	Vertex landmark_2("0007", 70.0, 0.0, "T07");
	path1.push_back(landmark_2);
	vector<Edge> result2;
	l1.find(result2, source_1, dest_1, path1);
	for (unsigned i = 0; i < result2.size(); i++) {
		cout << "from " << result2[i].source.getiata() << " to " << result2[i].dest.getiata() << endl;
	}
	// Graph g = a.getGraph();
	// g.showStats();

}
