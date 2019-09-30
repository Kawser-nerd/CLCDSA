#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:60000000")

#include <iostream>
#include <sstream>

#include <cassert>
#include <cmath>
#include <ctime>

#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define all(a) a.begin(), a.end()

const int INF = INT_MAX >> 1;
const double EPS = 1E-8;
const double PI = 3.1415926535897932384626433832795;

#define N 6000

int a[N], b[N], c[N], n;

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tk;
	scanf("%d\n", &tk);
	
	set<int> s1, s2;
	for(int tc = 1; tc <= tk; ++tc) {
		cin >> n;
		for(int i = 0; i < n; ++i)
			scanf("%d %d %d", &a[i], &b[i], &c[i]);

		int ans = 0;
		forn(l, n) {
			vector<pair<int, int> > v;
			forn(i, n)
				if (a[i] <= a[l]) v.pb(mp(b[i], c[i]));
			
			sort(all(v));
			int p = 0;
			priority_queue<int> q;
			forn(i, v.size()) {
				while (p < (int)v.size() && v[p].fs <= v[i].fs) {
					q.push(v[p++].sc);
				}
				int z = 10000 - a[l] - v[i].fs;
				while (!q.empty() && q.top() > z) q.pop();
				ans = max(ans, (int)q.size());
			}
		}

		printf("Case #%d: %d\n", tc, ans);
	}

	return 0;
}