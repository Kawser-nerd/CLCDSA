/*
    Author: Nikolay Kuznetsov
    Dedicated to my Love, Kristina Dmitrashko
*/
#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#include <memory.h>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define y1 YYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int bit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline int64 nextInt64() { int64 x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

struct point {
	int x, y, id;
	point () {}
	point (int X, int Y) {
		x = X;
		y = Y;
	}
};

point operator - (point &a, point &b){
	return point(a.x - b.x, a.y - b.y);
}

int vmul(point &a, point &b){
	int d = a.x*b.y - a.y*b.x;
	if (d == 0) return 0;
	if (d < 0) return -1;
	return 1;
}

void buildLine(point &a1, point &a2, int &a, int &b, int &c){
	a = a1.y - a2.y;
	b = a2.x - a1.x;
	c = - (a*a1.x + b*a1.y);
}

bool intersect(point &a1, point &b1, point &a2, point &b2){
	if (vmul(b1 - a1, a2 - a1) != vmul(b1 - a1, b2 - a1))
		if (vmul(b2 - a2, a1 - a2) != vmul(b2 - a2, b1 - a2))
			return true;

	if (max(min(a1.x, b1.x), min(a2.x, b2.x)) > min(max(a1.x, b1.x), max(a2.x, b2.x)))
		return false;

	if (max(min(a1.y, b1.y), min(a2.y, b2.y)) > min(max(a1.y, b1.y), max(a2.y, b2.y)))
		return false;

	int aa1, bb1, cc1;
	buildLine(a1, b1, aa1, bb1, cc1);

	int aa2, bb2, cc2;
	buildLine(a2, b2, aa2, bb2, cc2);

	if (aa1*bb2 == aa2*bb1 && aa1*cc2 == aa2*cc1)
		return true;

	return false;
}

bool parallel(point &a, point &b){
	return (vmul(a, b) == 0 && a.x*b.x + a.y*b.y > 0);
}

point a[15], l[15];
vector<int> ans;
bool used[15];
int n, maxs;

bool valid(int n, point &a){
	forn(i, n - 2)
		if (intersect(l[i], l[i + 1], a, l[n - 1]))
			return false;

	return (n == 1 || !parallel(a - l[n - 1], l[n - 2] - l[n - 1]));
}

void solve(int pos){
	if (pos == n){
		for(int i = 1; i < n - 2; i++)
			if (intersect(l[0], l[n - 1], l[i], l[i + 1]))
				return;

		int s = 0;
		vector<int> p;
		forn(i, n) {
			p.pb(l[i].id);
			int j = (i + 1) % n;
			s += (l[i].x - l[j].x) * (l[i].y + l[j].y);
		}

		s = abs(s);
		if (s > maxs) {
			maxs = s;
			ans = p;
		}
		
		return;
	}

	forn(i, n)
		if (!used[i] && valid(pos, a[i])){
			used[i] = true;
			l[pos] = a[i];
			solve(pos + 1);
			used[i] = false;
		}
}

void solve(bool skip) {
	n = nextInt();
	forn(i, n) {
		a[i].x = nextInt();
		a[i].y = nextInt();
		a[i].id = i;
	}

	memset(used, 0, sizeof used);
	used[0] = true;
	l[0] = a[0];
	maxs = -1;
	solve(1);

	forn(i, ans.size())
		cout << ans[i] << " ";
	cout << endl;
}

int main(int argc, char * argv[]) {
#ifdef NALP_PROJECT
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int L = 1, R = INF;
	if (argc >= 3) {
		L = atoi(argv[1]);
		R = atoi(argv[2]);
	}

	srand((unsigned int)time(0));
	int tests = nextInt();
	forn(test, tests) {
		time_t start = clock();
		cerr << "Case #" << test + 1 << endl;
		cout << "Case #" << test + 1 << ": ";
		solve(test < L-1 || test > R-1);
		cerr << "time is " << (0.0 + clock() - start) / CLOCKS_PER_SEC << endl;
	}

	return 0;
}
