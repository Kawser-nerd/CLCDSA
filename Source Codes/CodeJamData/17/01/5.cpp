#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXT64
#define prev PREV64
#define y1 Y164

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr(T x) { return x * x; }

string s;
int k;

void solve() {
	cin >> s >> k;
	int res = 0;
	for (int i = 0; i + k <= I s.length(); i++) {
		if (s[i] == '-') {
			res++;
			forn(j, k) s[i+j] = s[i+j] == '+' ? '-' : '+';
		}
	}
	forn(i, s.length()) {
		if (s[i] != '+') {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}
	cout << res << endl;
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	forn(i, t) {
		printf("Case #%d: ", i + 1);
		solve();
	}
}

