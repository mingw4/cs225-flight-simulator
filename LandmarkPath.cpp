#include "LandmarkPath.h"


LandmarkPath::LandmarkPath(const AirGraph &airGraph) {
    airGraph_ = airGraph;
}

    vector<Edge> LandmarkPath::findWithDijkstra(Vertex &start, Vertex &end, const vector<Vertex> &landmarks) {
        Vertex src = start;
        vector<Edge> edges;
        for (auto dest : landmarks) {
            Dijkstra dijkstra(airGraph_, src);
            const vector<Edge> &path = dijkstra.shortestPathTo(dest);
            if (path.empty()) {
                return {};
            } else {
                edges.insert(edges.end(), path.begin(), path.end());
                src = dest;
            }
        }

        Dijkstra dijkstra(airGraph_, src);
        const vector<Edge> &path = dijkstra.shortestPathTo(end);
        if (path.empty()) {
            return {};
        } else {
            edges.insert(edges.end(), path.begin(), path.end());
        }

        return edges;
    }


    bool LandmarkPath::isNotVisited(string x, vector<Edge> path) {
        int size = path.size();
        for (int i = 0; i < size; i++)
            if (path[i].dest.getid() == x)
                return false;
        return true;
    }

    bool LandmarkPath::hasLandMarks(const vector<Edge> &path, const vector<Vertex>& landmarks) {
        vector<string> pathIds;
        pathIds.reserve(path.size());
        for (auto &i : path) {
            pathIds.push_back(i.dest.getid());
        }

        vector<string> landmarkIds;
        landmarkIds.reserve(landmarks.size());
        for (auto &i : landmarks) {
            landmarkIds.push_back(i.getid());
        }
        return std::includes(pathIds.begin(), pathIds.end(), landmarkIds.begin(), landmarkIds.end());
    }
