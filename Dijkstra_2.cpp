#include "Dijkstra_2.h"
Dijkstra::Dijkstra(AirGraph &airgraph, const Vertex &src) {
    graph = airgraph.getGraph();
    source = src;
    buildMap();
}
void Dijkstra::buildMap() {
    Node* start = new Node(source, 0, Vertex());
    store[source] = start;
    pq_.push(start);
    while (!pq_.empty()) {
        Node* curr = pq_.pop();
        vector<Vertex> adja = graph.getAdjacent(curr->curr);
        for (unsigned i = 0; i < adja.size(); i++) {
            // if the Vectex has been visited before
            if (visited.find(adja[i]) != visited.end()) {
                continue;
            }
            double dist = curr->dist + graph.getEdge(curr->curr, adja[i]).weight;
            // double dist = distance(curr->curr, adja[i]) + curr->dist;
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
                }
            }
        }
        // set current Vertex visited
        visited[curr->curr] = true;
    }
}

double Dijkstra::distanceTo(Vertex &dest) {
    // if given destination is unreachable
    if (visited.find(dest) == visited.end()) {
        return 10000.0;
    }
    return store.find(dest)->second->dist;
}

vector<Edge> Dijkstra::shortestPathTo(const Vertex &dest) {
    vector<Edge> toReturn;
    if (visited.find(dest) == visited.end()) {
        return toReturn;
    }
    Vertex curr = dest;
    while (curr != source) {
        Node* curr_node = store.find(curr)->second;
        Vertex prev = curr_node->pre;
        toReturn.insert(toReturn.begin(), graph.getEdge(prev, curr));
        curr = prev;
    }
    return toReturn;
}
Dijkstra::~Dijkstra() {
    for (auto i = store.begin(); i != store.end(); i++) {
        delete i->second;
    }
}
