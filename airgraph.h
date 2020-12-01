#pragma once
#include "graph.h"
#include<map>


class AirGraph {
	private:
		mutable std::map<string, Vertex> vertice;
		Graph g;
	public:
		AirGraph();
		Graph& getGraph();
		vector<string> split(string s, char sep);
};
