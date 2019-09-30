#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

const int MAXN = 200;

const ld EPS = 1e-18;

int N;
pair<ld, ld> CR[MAXN];
#define C first
#define R second

ld V;
ld X;

bool isgood(ld t) {
	ld vol, val;
	vol = V, val = 0;
	for(int i = 0; vol > EPS && i < N; i++) {
		ld v = min(CR[i].R * t, vol);
		vol -= v;
		val += CR[i].C * v;
	}
	if(vol > EPS) return false;
	if(val > EPS) return false;

	vol = V, val = 0;
	for(int i = N - 1; vol > EPS && i >= 0; i--) {
		ld v = min(CR[i].R * t, vol);
		vol -= v;
		val += CR[i].C * v;
	}
	if(vol > EPS) return false;
	if(val < -EPS) return false;

	return true;
}

ld go() {
	sort(CR, CR + N);
	if(CR[0].C > EPS || CR[N - 1].C < -EPS) {
		return -1.;
	}

	ld mi = 0, ma = 1e18;
	for(int i = 0; i < 2000; i++) {
		ld md = (mi + ma) / 2;
		if(isgood(md)) ma = md;
		else mi = md;
	}
	return ma;
}

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> N;
		cin >> V >> X;
		for(int i = 0; i < N; i++) {
			cin >> CR[i].R >> CR[i].C;
			CR[i].C -= X;
		}

		ld res = go();
		cout << "Case #" << t << ": ";
		if(res < -EPS) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << fixed << setprecision(10) << res << '\n';
		}
	}
	return 0;
}

// sum (vi) = V
// sum (vi * X) = VX
// sum (vi * C[i]) = VX
// sum (vi * (C[i] - X)) = 0
//
// 0 <= vi <= R[i] * t
