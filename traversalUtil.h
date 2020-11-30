/**
 * create a traversal using BFS.
 */

#pragma once

#include "graph.h"
#include "edge.h
#include "dataloader.h"
#include "vertex.h"
#include <iterator>
#include <cmath>
#include <list>
#include <queue>

struct vertex {
    int index;
    double weight;
    vertex(int i = int(), double w = double()) : index(i), weight(w) {}

};
class BFS {
    public:

        //BFS algorithm, add the airport for the traversal to visit
        void bfs(Vertex source, Vertex destination);


        //find the shortest path between all the vertices(airports)
        void shortestPath(const Graph &graph, int v, string aid, Vertex source);


        //check if the certain airport is visited
        bool hasVisited(Vertex v);


    private:
    
        std::queue<vector<Vertex>> travelPath; //storing the airports(vertices) travelled

        //stores the visited location
        bool *visited;

        //stores the distance between two vertices
        vector<double> distBwVertices;

        std::priority_queue<Vertex> pq;

        //keep track of whether an aiport is visted, first: airport id
        std::vector<pair<string, bool>> visited;
        
};