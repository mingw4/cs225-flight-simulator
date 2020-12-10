#include "traversalUtil.h"

#include <list>
#include <iostream>



/** implement a bfs traversal
* @param graph - the airgraph from "airgraph.h"
* @param start - the starting vertex of the traversal
 */

void traversal::bfs(Graph &graph, Vertex source) {

    std::list<Vertex> priorityQueue;
    priorityQueue.push_back(source);
    visited[source] = true;

    while(!priorityQueue.empty()) {
        Vertex curr = priorityQueue.front();
        priorityQueue.pop_front();
        vector<Vertex> adjVector = graph.getAdjacent(curr);
        for(std::size_t i = 0; i < adjVector.size(); i++) {

            //if this vertex hasn't been visited 
            if(visited.find(adjVector[i]) == visited.end()) {
                Vertex next = adjVector[i];
                priorityQueue.push_back(next);
                visited[next] = true;
            }
        }
    }
    
}


