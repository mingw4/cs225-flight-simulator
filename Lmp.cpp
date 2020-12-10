#include "Lmp.h"


LandmarkPath::LandmarkPath(AirGraph& ag): ag_(ag) {
}


vector<vector<int>> sequence(vector<int> xv) {
	vector<vector<int>> ret;
	if (xv.size() == 1) {
		ret.push_back(xv);
		return ret;
	}
	for (int i = 0; i < (int) xv.size(); i++) {
		vector<int> temp = xv;
		int tt = temp[i];
		temp.erase(temp.begin() + i);
		vector<vector<int>> subseq = sequence(temp);
		for (vector<int> &subv : subseq) {
			subv.insert(subv.begin(), tt);
		}
		ret.insert(ret.begin(), subseq.begin(),subseq.end());
	}
	return ret;
}
vector<vector<int>> sequenceGen(int x) {
    vector<int> temp;
    for (int i = 0; i < x; i++) {
        temp.push_back(i);
    }
    return sequence(temp);
}

void LandmarkPath::find(vector<Edge>& ev, Vertex& source, Vertex& dest, vector<Vertex>& vv) {
	Dijkstra ds(ag_, source);
	if (vv.size() == 0) {
		ev = ds.shortestPathTo(dest);
		return;
	}
	vector<Dijkstra> dj;
	unordered_map<Vertex, unordered_map<Vertex, double>> dist_map;
	unordered_map<Vertex, unordered_map<Vertex, vector<Edge>>> path_map;
	for (Vertex& v1 : vv) {
		Dijkstra d(ag_, v1);
		dist_map[v1] = unordered_map<Vertex, double>();
		path_map[v1] = unordered_map<Vertex, vector<Edge>>();
		for (Vertex& v2 : vv) {
			if (v1 == v2) continue;
			double distance = d.distanceTo(v2);
			dist_map[v1][v2] = distance;
			path_map[v1][v2] = d.shortestPathTo(v2);
		}
		dist_map[v1][dest] = d.distanceTo(dest);
		path_map[v1][dest] = d.shortestPathTo(dest);
	}
	double min = 1000.0;
	//vector<Edge> ret;
	for (vector<int> seq : sequenceGen(vv.size())) {
		vector<Edge> path;
		auto tt_p = ds.shortestPathTo(vv[seq[0]]);
		path.insert(path.begin(), tt_p.begin(), tt_p.end());
		double sum = ds.distanceTo(vv[seq[0]]);
		for (int i = 0; i < (int) seq.size() - 1; i ++) {
			sum += dist_map[vv[seq[i]]][vv[seq[i+1]]];
			auto temp_path = path_map[vv[seq[i]]][vv[seq[i+1]]];

			path.insert(path.end(), temp_path.begin(), temp_path.end());
			if (sum > min) break;
		}
		sum += dist_map[vv[seq[seq.size() - 1]]][dest];
		if (sum < min) {
			auto t_p = path_map[vv[seq[vv.size() - 1]]][dest];
			path.insert(path.end(), t_p.begin(), t_p.end());
			min = sum;
			ev = path;
		}
	}
	
}
