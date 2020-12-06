#pragma once


#include "Dijkstra.h"

#include "airgraph.h"
#include "vertex.h"
#include "edge.h"

class LandmarkPath {
public:
    LandmarkPath(const AirGraph& airGraph);

    vector<Edge> findWithDijkstra(Vertex &start, Vertex &end, const vector<Vertex> &landmarks);
    vector<Edge> findWithBfs(Vertex &start, Vertex &end, const vector<Vertex> &landmarks);

private:
    AirGraph airGraph_;
    static bool hasLandMarks(const vector<Edge> &path, const vector<Vertex>& landmarks);
    static bool isNotVisited(string x, vector<Edge> path);
};
