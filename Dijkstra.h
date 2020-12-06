#pragma once

#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include "airgraph.h"
#include "vertex.h"
#include "edge.h"

using std::vector;
using std::priority_queue;

    //This is a tentative head file for dijkstra algorithm. For invoke usage of Landmark only. Other teammate will overwrite this  file with formal version.

    /**
     * vertex used only for dijkstra algorithm, as a helper for running dijkstra instead of using Vertex
     */
    class WeightedVertex {
        public: 
            int index;
            double weight;

            WeightedVertex(int i = int(), double w = double()) : index(i), weight(w) {}

            friend
            bool operator<(const WeightedVertex &x, const WeightedVertex &y) {
                return x.weight > y.weight;
            }

            friend bool
            operator>(const WeightedVertex &x, const WeightedVertex &y) {
                return x.weight < y.weight;
            }
    };

    class Dijkstra {
    public:
        Dijkstra(const AirGraph &airgraph, const Vertex &src);

        double distanceTo(int v);

        vector<Edge> shortestPathTo(const Vertex &dest);

    private:
        vector<Edge> predecessor_;
        vector<double> distanceTo_;
        priority_queue<WeightedVertex> pq_;
        const double infinite_ = std::numeric_limits<double>::infinity();

        bool hasPathTo(int v);
    };
