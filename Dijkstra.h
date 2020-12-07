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
#include "airgraph.cpp"
#include "vertex.h"
#include "edge.h"
#include "Node.cpp"
#include "heap.h"
#include <unordered_map>

using std::vector;

    //This is a tentative head file for dijkstra algorithm. For invoke usage of Landmark only. Other teammate will overwrite this  file with formal version.

    /**
     * vertex used only for dijkstra algorithm, as a helper for running dijkstra instead of using Vertex
     */
    // class WeightedVertex {
    //     public: 
    //         int index;
    //         double weight;

    //         WeightedVertex(int i = int(), double w = double()) : index(i), weight(w) {}

    //         friend
    //         bool operator<(const WeightedVertex &x, const WeightedVertex &y) {
    //             return x.weight > y.weight;
    //         }

    //         friend bool
    //         operator>(const WeightedVertex &x, const WeightedVertex &y) {
    //             return x.weight < y.weight;
    //         }
    // };

    class Dijkstra {
    public:
        Dijkstra(AirGraph airgraph, const Vertex &src);
        // find distance from source to dest
        double distanceTo(Vertex &dest);
        ~Dijkstra();
        // find all edges in path from source to dest
        vector<Edge> shortestPathTo(const Vertex &dest);


    private:
        Graph graph;
        Vertex source;
        //find the nearnest point to run in next iteration
        heap pq_;
        //store visited points
        unordered_map<Vertex, bool> visited;
        //mapped from Vertex to Node
        std::unordered_map<Vertex, Node*> store;
        // find distance from source to every point
        void buildMap();     
    };
