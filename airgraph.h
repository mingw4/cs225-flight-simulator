#pragma once
#include "graph.h"


class AirGraph {
	private:
		mutable unordered_map<string, Vertex> vertice;
		Graph g;
	public:
		AirGraph();
		vector<string> split(string s, char sep);
};
