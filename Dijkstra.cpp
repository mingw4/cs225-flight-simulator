#include "Dijkstra.h"
#include <queue>

using std::cout;
using std::endl;
using std::stoi;

Dijkstra::Dijkstra(const AirGraph &graph, const Vertex &src) {
    int fromId = stoi(src.getid());
    distanceTo_.resize(graph.vSize(), infinite_);
    predecessor_.resize(graph.vSize());

    distanceTo_[fromId] = 0;
    pq_.push(WeightedVertex(fromId, 0));
    while (!pq_.empty()) {
        int index = pq_.top().index;
        pq_.pop();
        for (const Edge &route : graph.getAdjacent(src)) {
            int v = stoi(route.dest.getid());
            if (distanceTo_[v] > distanceTo_[index] + route.weight) {
                distanceTo_[v] = distanceTo_[index] + route.weight;
                predecessor_[v] = route;
                pq_.push(WeightedVertex(v, distanceTo_[v]));
            }
        }
    }
}

    double Dijkstra::distanceTo(int v) {
        return distanceTo_[v];
    }

    bool Dijkstra::hasPathTo(int v) {
        return distanceTo_[v] < infinite_;
    }

    vector<Edge> Dijkstra::shortestPathTo(const Vertex &dest) {
        int v = stoi(dest.getid());
        vector<Edge> path;
        if (hasPathTo(v)) {
            for (Edge e = predecessor_[v]; stoi(e.source.getid()) != 0; e = predecessor_[stoi(e.source.getid())]) {
                path.push_back(e);
            }
        }
        std::reverse(path.begin(), path.end());
        return path;
    }