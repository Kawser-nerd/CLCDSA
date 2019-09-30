#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>
#include <bitset>
using namespace std;

class Timer {
	chrono::high_resolution_clock::time_point start, end;
	double limit;

public:
	Timer() {
		start = chrono::high_resolution_clock::now();
	}
	Timer(double l) {
		start = chrono::high_resolution_clock::now();
		limit = l;
	}

	double getTime() {
		end = chrono::high_resolution_clock::now();
		return chrono::duration<double>(end - start).count();
	}

	bool Over() {
		if (getTime() > limit) {
			return true;
		}
		return false;
	}

	void setLimit(double l) {
		limit = l;
	}
	void setStart() { start = chrono::high_resolution_clock::now(); }
	double getLimit() { return limit; }
};


class Xor128 {
	unsigned static int x, y, z, w;
public:
	Xor128() {
		x = 31103110, y = 123456789, z = 521288629, w = 88675123;
	}

	unsigned int rand()
	{
		unsigned int t;
		t = (x ^ (x << 11)); x = y; y = z; z = w;
		return(w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
	}
};
unsigned int Xor128::x, Xor128::y, Xor128::z, Xor128::w;

int H, W;
int H2, W2;
bool mode = false;
bitset<5> GRID[12][12];
char odd = -1;
int ni = -1, nj = -1;
void swapGRID(int m, int i, int j) {
	if (m) {
		for (int k = 0; k < H; k++)swap(GRID[k][i], GRID[k][j]);
	}
	else {
		for (int k = 0; k < W; k++)swap(GRID[i][k], GRID[j][k]);
	}
}
bool is_() {
	bool flag = true;

	if (mode) {
		if (GRID[H2][W2] != odd)return false;
	}

	for (int i = 0; flag && i < H; i++) {
		for (int j = 0; flag && j < W; j++) {
			if (GRID[i][j] != GRID[H - 1 - i][W - 1 - j]) {
				ni = i, nj = j;
				flag = false;
			}
		}
	}
	return flag;
}

int main() {
	cin >> H >> W;
	if (H % 2 && W % 2)mode = true;
	H2 = H / 2; W2 = W / 2;
	vector<int>cnt(26);
	for (int i = 0; i < H; i++)for (int j = 0; j < W; j++) {
		char c; cin >> c;
		GRID[i][j] = c;
		cnt[c - 'a']++;
	}
	int oddcnt = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2) {
			oddcnt++;
			odd = 'a' + i;
		}
	}

	if (oddcnt > 1) {
		cout << "NO" << endl;
		return 0;
	}
	else if (oddcnt == 1 && !mode) {
		cout << "NO" << endl;
		return 0;
	}
	else if (oddcnt == 0 && mode) {
		cout << "NO" << endl;
		return 0;
	}

	if (H == 1 && W == 1) {
		cout << "YES" << endl;
		return 0;
	}

	Timer tmr;

	Xor128 rnd;
	int loop = 0;
	while (1) {
		if (loop % 100000 == 0) {
			if (tmr.getTime()>1.9)break;
		}

		int m, i, j;
		m = rnd.rand() % 2;
		if (H == 1)m = 1;
		if (W == 1)m = 0;

		if (m) {
			if(nj==-1)i = rnd.rand() % W;
			else i = nj;
			do {
				j = rnd.rand() % W;
			} while (i == j);
		}
		else {
			if (ni == -1)i = rnd.rand() % H;
			else i = ni;
			do {
				j = rnd.rand() % H;
			} while (i == j);
		}


		swapGRID(m, i, j);
		if (is_()) {
			cout << "YES" << endl;
			return 0;
		}

		loop++;
	}
	cout << "NO" << endl;

	return 0;
}