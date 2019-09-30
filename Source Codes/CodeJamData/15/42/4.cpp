#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

#define double long double

int T;
int N; double V, X, R[120], C[120];

double test(double t)
{
	vector<pair<double, double> > vec;
	for (int i = 0; i < N; ++i) {
		vec.push_back(make_pair(C[i], R[i] * t)); // (temp, amount)
	}

	sort(vec.begin(), vec.end());

	double remV, intVT;
	double VTMin, VTMax;

	remV = V;
	intVT = 0;
	for (int i = 0; i < N; ++i) {
		if (vec[i].second > remV) {
			intVT += vec[i].first * remV;
			remV = 0;
			break;
		} else {
			intVT += vec[i].first * vec[i].second;
			remV -= vec[i].second;
		}
	}

	if (remV != 0) return false;
	VTMin = intVT;

	reverse(vec.begin(), vec.end());
	remV = V;
	intVT = 0;
	for (int i = 0; i < N; ++i) {
		if (vec[i].second > remV) {
			intVT += vec[i].first * remV;
			remV = 0;
			break;
		} else {
			intVT += vec[i].first * vec[i].second;
			remV -= vec[i].second;
		}
	}

	if (remV != 0) return false;
	VTMax = intVT;

	if (VTMin <= V * X && V * X <= VTMax) return true;
	return false;
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;) {
		scanf("%d%LF%LF", &N, &V, &X);

		for (int i = 0; i < N; ++i) scanf("%LF%LF", R + i, C + i);

		double mn = 1000, mx = -1;
		for (int i = 0; i < N; ++i) {
			mn = min(mn, C[i]);
			mx = max(mx, C[i]);
		}

		if (X < mn || mx < X) {
			printf("Case #%d: IMPOSSIBLE\n", t);
			continue;
		}

		if (mn == mx) {
			double sumsp = 0;
			for (int i = 0; i < N; ++i) sumsp += R[i];
			printf("Case #%d: %.10LF\n", t, V / sumsp);
			continue;
		}

		double left = 0, right = 1e9;
		for (int i = 0; i < 80; ++i) {
			double mid = (left + right) / 2;
			if (test(mid)) {
				right = mid;
			} else {
				left = mid;
			}
		}

		printf("Case #%d: %.10LF\n", t, (left + right) / 2);
	}

	return 0;
}
