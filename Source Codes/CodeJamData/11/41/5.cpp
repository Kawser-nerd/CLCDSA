#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Walk {
	double B, E, w;
};

struct Seg {
	double D, I;
	Seg(double D, double I): D(D), I(I) {}
};

bool operator<(const Seg &s1, const Seg &s2) {
	return s1.I < s2.I;
}

bool operator < (const Walk &w1, const Walk &w2) {
	return w1.B < w2.B;
}

void solve() {
	double X, S, R, t;
	int N;
	cin >> X >> S >> R >> t >> N;
	vector<Walk> W(N);
	double dist = X;
	for (int i = 0; i < N; i++) {
		cin >> W[i].B >> W[i].E >> W[i].w;
	}
	sort(W.begin(), W.end());
	vector<Seg> segs;
	segs.push_back(Seg(W[0].B, 0.0));
	for (int i = 0; i < N; i++) {
		segs.push_back(Seg(W[i].E - W[i].B, W[i].w));
		if (i != N - 1) segs.push_back(Seg(W[i + 1].B - W[i].E, 0.0));
		else segs.push_back(Seg(X - W[i].E, 0.0));
	}
	sort(segs.begin(), segs.end());
	double res = 0.0;
	for (int i = 0; i < (int)segs.size(); i++) {
		double run = min(t, segs[i].D / (R + segs[i].I));
		t -= run;
		res += run + (segs[i].D - (R + segs[i].I) * run) / (S + segs[i].I);
	}
	printf("%.20lf\n", res);
}

int main() {
	int nt;
	scanf("%d", &nt);
	for (int it = 1; it <= nt; it++) {
		printf("Case #%d: ", it);
		solve();
	}
	return 0;
}
