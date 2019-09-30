#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int arr[1 << 15];
long long fact[20];


long long Solve(vector<int> v, int ops = 0) {
	if (v.size() == 1) {
		return fact[ops];
	} else {
		int bad1 = 0, bad2 = 0, qbad = 0;
		for (int i = 0; i < v.size(); i += 2) {
			if (v[i] + 1 != v[i + 1] || v[i] % 2 != 0) {
				bad2 = bad1;
				bad1 = i;
				++qbad;
			}
		}
		if (qbad > 2) {
			return 0;
		}
		if (qbad == 0 || qbad == 1) {
			vector<int> vv;
			for (int i = 0; i < v.size(); i += 2) {
				vv.push_back(v[i] / 2);
			}
			return Solve(vv, ops + qbad);
		} else {
			long long ret = 0;
			vector<int> vv;
			for (int i = 0; i < v.size(); i += 2) {
				vv.push_back(v[i] / 2);
			}

			swap(v[bad1], v[bad2]);
			if (v[bad1] + 1 == v[bad1 + 1] && v[bad2] + 1 == v[bad2 + 1]) {
				vv[bad1 / 2] = v[bad1] / 2;
				vv[bad2 / 2] = v[bad2] / 2;
				ret += Solve(vv, ops + 1);
			}
			swap(v[bad1], v[bad2]);

			swap(v[bad1], v[bad2 + 1]);
			if (v[bad1] + 1 == v[bad1 + 1] && v[bad2] + 1 == v[bad2 + 1]) {
				vv[bad1 / 2] = v[bad1] / 2;
				vv[bad2 / 2] = v[bad2] / 2;
				ret += Solve(vv, ops + 1);
			}
			swap(v[bad1], v[bad2 + 1]);

			swap(v[bad1 + 1], v[bad2]);
			if (v[bad1] + 1 == v[bad1 + 1] && v[bad2] + 1 == v[bad2 + 1]) {
				vv[bad1 / 2] = v[bad1] / 2;
				vv[bad2 / 2] = v[bad2] / 2;
				ret += Solve(vv, ops + 1);
			}
			swap(v[bad1 + 1], v[bad2]);

			swap(v[bad1 + 1], v[bad2 + 1]);
			if (v[bad1] + 1 == v[bad1 + 1] && v[bad2] + 1 == v[bad2 + 1]) {
				vv[bad1 / 2] = v[bad1] / 2;
				vv[bad2 / 2] = v[bad2] / 2;
				ret += Solve(vv, ops + 1);
			}
			swap(v[bad1 + 1], v[bad2 + 1]);
			return ret;
		}
	}
}

void Solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 1 << n; ++i) {
		scanf("%d", &arr[i]);
	}
	vector<int> v;
	for (int i = 0; i < 1 << n; ++i) {
		v.push_back(arr[i] - 1);
	}
	long long ret = Solve(v);
	cout << ret << endl;
}

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	fact[0] = 1;
	for (int i = 1; i < 15; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	int T, tc = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++tc);
		Solve();
	}
    	return 0;
}