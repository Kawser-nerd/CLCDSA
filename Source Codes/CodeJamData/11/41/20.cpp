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

const int MAXN = 10000;

int n;
int m;
double l[1001], u[1001], w[1001];
int p[1001];

bool l1 (int a, int b) {
	re w[a] < w[b];
}

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {
		double len, s, r, t;
		cin >> len >> s >> r >> t >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b >> w[i];
			l[i] = b - a;
			u[i] = 0;
			len -= l[i];
			p[i] = i;
		}
		l[n] = len;
		u[n] = 0;
		w[n] = 0;
		p[n] = n;
		n++;
		sort (p, p + n, l1);
		for (int i = 0; i < n; i++) {
			int j = p[i];
			double tmp = min (t, l[j] / (w[j] + r));
			u[j] += tmp;
			t -= tmp;
		}
		double tmp = 0;
		for (int i = 0; i < n; i++)
			tmp += u[i] + (l[i] - u[i] * (w[i] + r)) / (w[i] + s);
		printf ("Case #%d: %.10f\n", it, tmp);
//		for (int i = 0; i < n; i++) fprintf (stderr, "%.3f ", u[i]);
//		fprintf (stderr, "\n");
	}
	return 0;
}