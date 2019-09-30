#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Star {
	int x, y;
	bool operator<(const Star& s) const {return x*x + y*y > s.x*s.x + s.y*s.y;}
};

int N, M;
vector<Star> s;

double best;
double furthest;

void doit(int x, int y, int m) {
	double curd = sqrt(x*x + y*y);
	if (curd > best) best = curd;
	if (m == 0) return;
	if (m == 0 || curd + 2*furthest*m < best) return;
	for (int i = 0; i < N; i++)
		doit(s[i].x - (s[i].y - y), s[i].y + (s[i].x - x), m-1);
}

main() {
	int T, prob = 1;
	for (cin >> T; T--;) {
		cin >> N >> M;
		s.resize(N);
		for (int i = 0; i < N; i++) cin >> s[i].x >> s[i].y;
		sort(s.begin(), s.end());
		best = 0.0;
		furthest = sqrt(s[0].x*s[0].x + s[0].y*s[0].y);
		doit(0, 0, M);
		printf("Case #%d: %.9lf\n", prob++, best);
	}
}
