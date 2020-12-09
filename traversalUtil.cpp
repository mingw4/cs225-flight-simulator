#include "traversalUtil.h"



/** implement a bfs traversal
* @param graph - the airgraph from "airgraph.h"
* @param start - the starting vertex of the traversal
 */

void traversal::bfs(Graph &graph, Vertex source) {

    Node *startingPoint = new Node(source, 0, Vertex());
    // vertexToNode[source] = startingPoint;
    priorityQueue.push(source);

    while(!priorityQueue.empty()) {
        Vertex curr = priorityQueue.top();
        priorityQueue.pop();
        vector<Vertex> adjVector = graph.getAdjacent(curr);
        for(std::size_t i = 0; i < adjVector.size(); i++) {

            //if this vertex hasn't been visited 
            if(visited.find(adjVector[i]) == visited.end()) {
                Vertex next = adjVector[i];
                priorityQueue.push(next);
                visited[next] = true;
            }
        }
    }
}


