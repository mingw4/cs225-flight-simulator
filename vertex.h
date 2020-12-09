#pragma once

#include <string>

using std::string;

class Vertex {
	private:
		double lat;
		double lnt;
		string id;
		string iata;
	public:
		Vertex(string aid, double la, double lo, string i)
			: lat(la), lnt(lo), id(aid),iata(i) { }
		Vertex() : lat(91.0), lnt(181.0),id(""),iata("") { }
		Vertex(string aid) : id(aid) { }
		string getid() const {
			return id;
		}
		string getiata() const { return iata;}
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
