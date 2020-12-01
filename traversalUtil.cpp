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



void BFS::bfs(const Graph &graph, Vertex source, Vertex destination) {
    for(Vertex willVisit : graph.getAdjacent(source)) {
        visited.push_back(make_pair(willVisit.getid(), false));
    }

    list<Vertex> q;
    visited[0] = make_pair(source.getid(), true);
    q.push_back(source);

    
    while(!q.empty()) {
        source = q.front();
        q.pop_front();

        for(int i = 0; i < graph.getAdjacent(source).size(); i++) {
            if(visited[i].second != true) {
                visited[i].second = true;
                q.push_back(graph.getAdjacent(source)[i]);
            }
        }
    }
}