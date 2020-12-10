#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <vector>


#include "airgraph.h"
#include "Node.h"
#include "heap.h"
#include <unordered_map>


using std::vector;
using std::priority_queue;
    class Dijkstra {
    public:
        Dijkstra(AirGraph &airgraph, const Vertex &src);
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
