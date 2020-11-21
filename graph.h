#pragma once

#include <vector>
#include <unordered_map>


#include "vertex.h"
#include "edge.h"


using std::vector;
using std::unordered_map;

class Graph {
	public:
		//create a weighted directed graph.
		//we need it, nvm non-weighted or undirected graph.
		Graph();

		vector<Vertex> getAdjacent(Vertex source) const;
		
		Edge getEdge(Vertex source, Vertex destination) const;

		bool vertexExists (Vertex v) const;

		bool edgeExists(Vertex source, Vertex destination) const;

		void insertVertex(Vertex v);

		bool insertEdge(Vertex source, Vertex destination, double w, string s, int stop);

	private:
		mutable unordered_map<Vertex, unordered_map<Vertex, Edge>> adj_list;
		

};
