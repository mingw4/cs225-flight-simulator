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
			return id != other.id;
		}
		bool operator== (const Vertex& other) const {
			return id == other.id;
		}
		

		Vertex(const Vertex& other) {
			this->id = other.id;
			this->iata = other.iata;
			this->lat = other.lat;
			this->lnt = other.lnt;
		}
		Vertex& operator=(const Vertex& other) {
			if (this == &other) {
				return *this;
			}
			this->id = other.id;
			this->iata = other.iata;
			this->lat = other.lat;
			this->lnt = other.lnt;
			return *this;
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
