/**
 * create a traversal using BFS.
 */

#pragma once

#include "graph.h"
#include "edge.h
#include "vertex.h"
#include <iterator>
#include <cmath>
#include <list>
#include <queue>


class BFS {
    public:

        //BFS algorithm, add the airport for the traversal to visit
        void bfs(Vertex source, Vertex destination);


    private:
    
        std::queue<vector<Vertex>> travelPath; //storing the airports(vertices) travelled

        //stores the visited location
        bool *visited;
        
};