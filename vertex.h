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
		Vertex(string aid) : id(aid) { }
		string getid() const {
			return id;
		}
		double getLatitude() const {
			return lat;
		}
		double getLongtitude() const {
			return lnt;
		}
		bool operator!= (const Vertex& other) const {
			return this->id != other.id;
		}
		bool operator== (const Vertex& other) const {
			return this->id == other.id;
		}
};
namespace std {
	template<>
	struct std::hash<Vertex> {
		std::size_t operator()(const Vertex& v) const {
			return std::hash<string>()(v.getid());
		}
	};
}
