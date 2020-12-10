#include "Dijkstra.h"

class LandmarkPath {
	public:
		LandmarkPath(AirGraph& ag);

		void find(vector<Edge>& ev, Vertex& source, Vertex& dest, vector<Vertex>& vv);

	private:
		AirGraph &ag_;
	
};
