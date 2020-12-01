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

/**
 * check if a given airport is visited.
 * v - the given airpot
 */
bool BFS::hasVisited(Vertex v) {
    for(pair<string, bool> check : visited) {
        if(check.second == true) return true;
    }
    return false;
}


/** find the shortest path between vertices
 * graph - the airline graph
 * source = the starting point
 * aid - the airport id 
 */


void BFS::shortestPath(const Graph &graph, int v, string aid, Vertex source) {
    if()
}