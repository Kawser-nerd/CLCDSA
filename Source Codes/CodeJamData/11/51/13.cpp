#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define V2D(A, T, N, M, V) vector<vector<T> > A(N, vector<T>(M, V))
#define V3D(A, T, N, M, K, V) vector<vector<vector<T> > > A(N, vector<vector<T> >(M, vector<T>(K, V)))

struct P {

	double x, y;

	P() {}
	P(double x, double y): x(x), y(y) {}

	void load() {
		cin >> x >> y;
	}

	double operator*(P he) {
		return x * he.y - y * he.x;
	}
};

P getCross(P p1, P p2, double x) {
	return P(x, p1.y + (x - p1.x) / (p2.x - p1.x) * (p2.y - p1.y));
}

double calc(vector<P> &pl, vector<P> &pu, double x) {
	vector<P> p1;
	for (int i = 0; i < pl.size(); i++) {
		if (pl[i].x < x) {
			p1.push_back(pl[i]);
		}
		else {
			assert(i != 0);
			p1.push_back(getCross(pl[i - 1], pl[i], x));
			break;
		}
	}
	vector<P> p2;
	for (int i = 0; i < pu.size(); i++) {
		if (pu[i].x < x) {
			p2.push_back(pu[i]);
		}
		else {
			assert(i != 0);
			p2.push_back(getCross(pu[i - 1], pu[i], x));
			break;
		}
	}
	vector<P> pts(p1);
	copy(p2.rbegin(), p2.rend(), back_insert_iterator<vector<P> >(pts));
	double S = 0.0;
	for (int i = 0; i < pts.size(); i++) {
		S += pts[i] * pts[(i + 1) % pts.size()];
	}
	S = fabs(S);
	return S;
}

void solveTest() {
	double W;
	int L, U, G;
	cin >> W >> L >> U >> G;
	vector<P> pl(L), pu(U);
	for (int i = 0; i < L; i++) {
		pl[i].load();
	}
	for (int i = 0; i < U; i++) {
		pu[i].load();
	}
	vector<P> pts(pl);
	copy(pu.rbegin(), pu.rend(), back_insert_iterator<vector<P> >(pts));
	double S = 0.0;
	for (int i = 0; i < pts.size(); i++) {
		S += pts[i] * pts[(i + 1) % pts.size()];
	}
	S = fabs(S);
	cout << endl;
	cout.precision(20);
	for (int i = 0; i < G - 1; i++) {
		double SS = S / G * (i + 1);
		double l = 0, r = W;
		for (int j = 0; j < 200; j++) {
			double m = (l + r) / 2;
			if (calc(pl, pu, m) < SS) {
				l = m;
			}
			else {
				r = m;
			}
		}
		cout << (l + r) / 2 << endl;
	}
}

int main() {
	int nt;
	cin >> nt;
	for (int it = 1; it <= nt; ++it) {
		printf("Case #%d: ", it);
		solveTest();
	}
	return 0;
}
