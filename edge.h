#pragma once

#include <string>
#include "vertex.h"
using std::string;


class Edge
{
	public:

		Vertex source;
		Vertex dest;
		string label;
		double weight;
		int stops;
		

		Edge(Vertex u, Vertex v)
			: source(u), dest(v), label(""),weight(1), stops(0){ }
		Edge(Vertex u, Vertex v, string lbl) 
			: source(u), dest(v), label(lbl),weight(1), stops(0){ }
		Edge(Vertex u, Vertex v, double w,string lbl)
			: source(u), dest(v), label(lbl),weight(w), stops(0){ }
		Edge(Vertex u, Vertex v, double w,string lbl, int s) 
			:source(u), dest(v), label(lbl),weight(w), stops(s){ }

		Edge() 
			: source(), dest(), label(""),weight(0), stops(0) { }
		bool operator< (const Edge& other) const {
			return weight < other.weight;
		}
		bool operator==(Edge& other) const {
			if (this->source != other.source) return false;
			if (this->dest != other.dest) return false;
			return true;
		}
	
};
