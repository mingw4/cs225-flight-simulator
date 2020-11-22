/**
 * create a traversal using BFS.
 */

#pragma once

#include "graph.h"
#include <iterator>
#include <cmath>
#include <list>
#include <queue>


class BFS {
    public:

        //add the airport for the traversal to visit
        void add(const Vertex & airport);

    private:
    
        std::queue<Vertex> travelPath; //storing the airports(vertices) travelled
};