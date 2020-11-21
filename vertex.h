#pragma once

#include <string>

using std::string;

class Vertex {
	private:
		string id;
		double lat;
		double lnt;
	public:
		Vertex(string aid, double la, double lo)
			: id(aid), lat(la), lnt(lo) { }
		Vertex() : id(""), lat(91.0), lnt(181.0) { }
		string getid() {
			return id;
		}
		double getLatitude() {
			return lat;
		}
		double getLongtitude() {
			return lnt;
		}
		bool operator!= (const Vertex& other) const {
			return this->id != other.id;
			
		}
};
