#include <bitset>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	string s; int tx, ty;
	cin >> s >> tx >> ty; s += "T";
	vector<int> vx, vy; int dir = 0, cont = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'F') ++cont;
		else {
			if (dir == 0) vx.push_back(cont);
			else vy.push_back(cont);
			cont = 0;
			dir ^= 1;
		}
	}
	bitset<16001> bx, by;
	bx[8000 + vx[0]] = 1;
	for (int i = 1; i < vx.size(); ++i) {
		bx = (bx << vx[i]) | (bx >> vx[i]);
	}
	by[8000] = 1;
	for (int i = 0; i < vy.size(); ++i) {
		by = (by << vy[i]) | (by >> vy[i]);
	}
	cout << (bx[8000 + tx] && by[8000 + ty] ? "Yes" : "No") << endl;
	return 0;
}