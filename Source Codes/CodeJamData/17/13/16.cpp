#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const int INF = (int)(1e9);

map<pair<pair<int, int>, pair<int, int> >, int> mp;
int B, D, ST;

int rec(int hd, int ad, int hk, int ak) {
	auto o = make_pair(make_pair(hd, ad), make_pair(hk, ak));
	if (mp.count(o)) return mp[o];
	mp[o] = INF;

	int best = INF;
	{
		if (hk <= ad) best = 1;
		else if (hd > ak) {
			best = min(best, rec(hd - ak, ad, hk - ad, ak) + 1);
		}
	}
	if (hd > ak && ad < hk) {
		best = min(best, rec(hd - ak, ad + B, hk, ak) + 1);
	}
	int nak = max(0, ak - D);
	if (hd > nak) {
		best = min(best, rec(hd - nak, ad, hk, nak) + 1);
	} 
	if (ST > ak) {
		best = min(best, rec(ST - ak, ad, hk, ak) + 1);
	}
	return mp[o] = best;
}

int slowsolve(int hd, int ad, int hk, int ak, int b, int d) {
	mp.clear();
	B = b;
	D = d;
	ST = hd;
	return rec(hd, ad, hk, ak);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";
		cerr << "Case #" << test << ": ";
		
		int hd, ad, hk, ak, b, d;
		cin >> hd >> ad >> hk >> ak >> b >> d;

		int res = slowsolve(hd, ad, hk, ak, b, d);
		string ans = res >= INF ? "IMPOSSIBLE" : to_string(res);

		cout << ans << endl;
		cerr << ans << endl;
	}

	return 0;
}