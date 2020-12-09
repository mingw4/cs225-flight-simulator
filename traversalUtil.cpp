#include "traversalUtil.h"



/** implement a bfs traversal
* @param graph - the airgraph from "airgraph.h"
* @param start - the starting vertex of the traversal
 */

void traversal::bfs(Graph &graph, Vertex source) {

    Node *startingPoint = new Node(source, 0, Vertex());
    vertexToNode[source] = startingPoint;
    priorityQueue.push(startingPoint);

    while(!priorityQueue.empty()) {
        Node *curr = priorityQueue.pop();
        vector<Vertex> adjVector = graph.getAdjacent(curr -> curr);
        for(size_t i = 0; i < adjVector.size(); i++) {

            //if this vertex hasn't been visited 
            if(visited.find(adjVector[i]) != visited.end()) {
                auto next = vertexToNode.find(adjVector[i]);

                // map the "next" vertex if not already existed 
                if (next == vertexToNode.end()) {
                    Node* new_node = new Node(adjVector[i], 0, curr->curr);
                    priorityQueue.push(new_node);
                    vertexToNode[adjVector[i]] = new_node;
                }
            }
        }

        //set the vertices as visited 
        visited[curr -> curr] = true;
    }
}