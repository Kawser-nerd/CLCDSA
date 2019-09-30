#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

bool issq(int64 a) {
	int64 r = (int64)sqrt((long double)a);

	for (int64 i = r - 30; i <= r + 30; i++)
		if (i * i == a)
			return true;
	return false;
}

void solve() {
	string s;
	cin >> s;

	vector<int> v;
	forn(i, s.size())
		if (s[i] == '?')
			v.pb(i);

	int n = (int)v.size();
	forn(ma, 1 << n) {
		string c = s;
		forn(i, n)
			if (ma & (1 << i))
				c[v[i]] = '1';
			else
				c[v[i]] = '0';

		int64 cur = 0;
		forn(i, c.size())
			cur = cur * 2 + (c[i] - '0');

		if (issq(cur)) {
			cout << c << endl;
			return;
		}
	}
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif	
	
	int tt;
	scanf("%d", &tt);
	forn(ii, tt) {
		cerr << ii << ' ' << clock() << endl;
		printf("Case #%d: ", ii + 1);

		solve();
	}

	cerr << clock() << endl;
	
	return 0;
}