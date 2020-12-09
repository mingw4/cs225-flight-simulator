/* Implement a BFS traversal */

#pragma once

#include "airgraph.h"
#include "vertex.h"
#include "edge.h"
#include "graph.h"


#include <map>
#include <vector>
#include <unordered_map>
#include <iostream> 
#include <queue>
#include <cstddef>
#include <stddef.h>



class traversal {
    public:

        /** implement a bfs traversal
         * @param graph - the airgraph from "airgraph.h"
         * @param start - the starting vertex of the traversal
         */
        void bfs(Graph &graph, Vertex source);

    private:
        //store the visited vertices 
        std::unordered_map<Vertex, bool> visited;

        //use heap as priority queue to find the nearest vertex for next iteration
        std::priority_queue<Vertex> priorityQueue;

        //the number of vertices in the graph
        int numberOfVertices;

};