#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;
double v[1000000];
int x[1000000];

bool check (double s) {
	v[0] = -1;
	for (int i = 1; i < n; i++) {
		v[i] = max (-1.0, (m - x[i] + x[i - 1]) / s + v[i - 1]);
		if (v[i] > 1) re false;
	}
	re true;
}

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {
//		cerr << it << endl;
		int k;
		scanf ("%d%d", &k, &m);
		n = 0;
		for (int i = 0; i < k; i++) {
			int x, y;
			scanf ("%d%d", &x, &y);
			for (int j = 0; j < y; j++)
				::x[n++] = x;
		}
		double l = 0, r = 1e13;
		for (int t = 0; t < 100; t++) {
			double s = (l + r) / 2;
			if (check (s)) r = s; else l = s;
		}
		printf ("Case #%d: %.10f\n", it, (l + r) / 2);
	}
	return 0;
}