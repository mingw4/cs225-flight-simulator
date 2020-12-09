#include "Dijkstra.h"
<<<<<<< HEAD
#include <queue>

using std::cout;
using std::endl;
using std::stoi;

namespace algorithms {
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
=======


Dijkstra::Dijkstra(AirGraph airgraph, const Vertex &src) {
    graph = airgraph.getGraph();
    source = src;
    buildMap();
}
void Dijkstra::buildMap() {
    Node* start = new Node(source, 0, Vertex());
    store[source] = start;
    pq_.push(start);
    while (!pq_.empty()) {
        Node* curr = pq_.top(); pq_.pop();
        vector<Vertex> adja = graph.getAdjacent(curr->curr);
        for (unsigned i = 0; i < adja.size(); i++) {
            // if the Vectex has been visited before
            if (visited.find(adja[i]) != visited.end()) {
                continue;
            }
            double dist = 1.0; //getDistance(curr->curr, adja[i]) + curr->dist;
            auto next = store.find(adja[i]);
            // if haven't calculate distance of the Vertex before
            if (next == store.end()) {
                Node* new_node = new Node(adja[i], dist, curr->curr);
                pq_.push(new_node);
                store[adja[i]] = new_node;
            } else {
                // if smaller distance found
                if (next->second->dist > dist) {
                    next->second->dist = dist;
                    next->second->pre = curr->curr;
>>>>>>> a53899850b7e34fc15103bf2c43b5445ea22bcc2
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
}