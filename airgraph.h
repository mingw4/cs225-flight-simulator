#pragma once

#include "graph.h"
class AirGraph {
	private:
		mutable std::unordered_map<string, Vertex> vertice;
		mutable std::unordered_map<string, string> codetable;
		Graph g;
	public:
		AirGraph();
		AirGraph(string a, string r);
		Graph& getGraph();
		void setG(Graph& gr);
		vector<string> split(string s, char sep);
		string getid(const string& k) const;
		Vertex getVertex(const string& k) const;
		vector<Vertex> getAdjacent(const Vertex& v);
		Edge getEdge(const Vertex& s, const Vertex& e);
		int vSize() const;
		double distance(Vertex n1, Vertex n2);
};
