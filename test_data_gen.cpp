#include <fstream>
#include <vector>

using std::ofstream;
using std::endl;
int main() {
	ofstream out;
	out.open("./autoport.dat.txt");
	ofstream out1;
	out1.open("./autoroute.dat.txt");
	
	for (int i = 0; i < 10; i ++) {
		for (int j = 0; j < 10; j++) {
			out << i << "00"<< j << ",";
			out << "\"" << i << "\",";
			out << "\"" << j << "\",";
			out << "\"" << "loc in set"<< i << "\",";
			out << "\"" <<"T"<< i << j << "\",";
			out << "\"" << "TES" << j << "\",";
			out << j * 10 << ".0"<< ",";
			out << i * 10 <<".0" <<",";
			out << "\"" << 0 << "\",";
			out << "\"" << 0 << "\",";
			out << "\"" << "U" << "\",";
			out << "\"" << "Test/Test" << "\",";
			out << "\"" << "airport" << "\",";
			out << "\"" << "Test" << "\""<<endl;
			for (int k = 0; k < 10; k ++) {
				if (k == j) continue;
				out1 << "TE" << i << ",";
				out1 << "00" << i << ",";
				out1 << "T" << i << j << ",";
				out1 << i << "00" << j << ",";
				out1 << "T" <<i <<k << ",";
				out1 << i << "00" << k << ",";
				out1 <<"" << ",";
				out1 << 0 << ",";
				out1 << "787" << endl;
				
			}
		}
		if (i < 9) {
			out1 << "TE" << i << ",";
            out1 << "00" << i << ",";
            out1 << "T" << i << 0 << ",";
            out1 << i << "00" << 0 << ",";
            out1 << "T" <<i + 1 << 0 << ",";
            out1 << i + 1<< "00" << 0 << ",";
            out1 << ",";
            out1 <<  0 << ",";
            out1 << "787"  << endl;

			out1 << "TE" << i << ",";
            out1 << "00" << i << ",";
            out1 << "T" << i + 1 << 0 << ",";
            out1 << i + 1 << "00" << 0 << ",";
            out1 << "T" << i << 0 << ",";
            out1 << i << "00" << 0 << ",";
            out1 << ",";
            out1 <<  0 << ",";
            out1 << "787"  << endl;

			out1 << "TE" << i << ",";
            out1 << "00" << i << ",";
            out1 << "T" << i + 1 << 4 << ",";
            out1 << i + 1 << "00" << 4 << ",";
            out1 << "T" <<i << 4 << ",";
            out1 << i << "00" << 4 << ",";
            out1 << ",";
            out1 << 0 << ",";
            out1 << "787" << endl;

			out1 << "TE" << i << ",";
            out1 << "00" << i << ",";
            out1 << "T" << i << 4 << ",";
            out1 << i << "00" << 4 << ",";
            out1 << "T" << i + 1 << 4 << ",";
            out1 << i + 1<< "00" << 4 << ",";
            out1 << ",";
            out1 << 0 << ",";
            out1 << "787" << endl;
		}
	}
	
	return 0;
}
