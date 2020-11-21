

#include "graph.h"


Graph() { }



vector<Vertex> Graph::getAdjacent(Vertex source) const {
	vector<Vertex> ret;
	auto lookup = adj_list.find(source);

	if (lookup == adj_list.end()) return ret;
	unordered_map<Vertex, Edge> & map = adj_list[source];
	for (auto it = map.begin();it != map.end(); it++) {
		ret.push_back(it->first);
	}
	return ret;
	
}

Edge Graph::getEdge(Vertex source , Vertex destination) const {
	if (edgeExists(source, destination)) {
		return adj_list[source][destination];
	}
	return Edge();
}

bool Graph::vertexExists(Vertex v) const {
	if (adj_list.find(v) == adj_List.end()) {
		return false;
	}
	return true;
}


bool Graph::edgeExists(Vertex source, Vertex destination) const {
	if (adj_list.find(source) == adj_List.end()) {
		return false;
	}
	if (adj_list[source].find(destination) == adj_list[source].end()) {
		return false;
	}
	return true;
}

void Graph::insertVertex(Vertex v) {
	if (adj_list.find(v) != adj_list.end()) return;

	adj_list[v] = unordered_map<Vertex, Edge>();


}


bool Graph::insertEdge(Vertex source, Vertex destination, double w, string lbl, int stop) {
	if (adj_list.find(source) != adj_list.end() 
		&& adj_list[source].find(destination) != adj_list[source].end()) {
		return false;
	}
	if (adj_list.find(source) == adj_list.end()) {
		adj_list[source] = unordered_map<Vertex, Edge>();
	}
	adj_list[source][destination] = Edge(source, destination, w, lbl, stop);
	return true;
}




