#include "traversalUtil.h"


/** add the airport for the traversal to visit
 * airport - vertex to travel
 */

void BFS::bfs(Vertex source, Vertex destination) {
    //create a vector to store the current path
    std::vector<Vertex> path;
    std::queue<vector<Vertex>> q;
    path.push_back(source);
    q.push(path);
    while(!travelPath.empty()) {
        path = q.front();
        q.pop();
        Vertex last = path[path.size() - 1];

        if(last == destination) {
            travelPath.push(path);
        }

    }
}

/** find the shortest path between vertices
 * graph - the airline graph
 * source = the starting point
 * aid - the airport id 
 */


void BFS::shortestPath(const Graph &graph, int source, string aid) {
    return;
    // distBwVertices.resize(std::numeric_limits<double>::infinity());
    // distBwVertices[source] = 0;
    // //push the starting point to the priority queue
    // pq.push(vertex(source, 0));
    // while(!pq.empty()) {
    //     int index = pq.top().index;
    //     pq.pop();
    //     for()
    // }
}