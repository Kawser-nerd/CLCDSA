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
int x[2000];
int y[2000];
int was[3000][21];
int ans[3000][21];

int go (int c, int p) {
	if (c >= m - 1) {
		if (x[c - m + 1] < p) return -1;
		return 0;
	}
	if (was[c][p]) return ans[c][p];
	int res = -1;
	int rl = go (c * 2 + 1, p);
	int rr = go (c * 2 + 2, p);
	if (rl != -1 && rr != -1 && (res == -1 || res != -1 && res > rl + rr + y[c])) res = rl + rr + y[c];
	rl = go (c * 2 + 1, p + 1);
	rr = go (c * 2 + 2, p + 1);
	if (rl != -1 && rr != -1 && (res == -1 || res != -1 && res > rl + rr)) res = rl + rr;
	was[c][p] = 1;
	ans[c][p] = res;
	return res;
}

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		m = 1 << n;
		for (int i = 0; i < m; i++) scanf ("%d", &x[i]);
		for (int i = n - 1; i >= 0; i--) 
			for (int j = (1 << i) - 1; j < (1 << (i + 1)) - 1; j++) scanf ("%d", &y[j]);
		memset (was, 0, sizeof (was));
		printf ("Case #%d: %d\n", it + 1, go (0, 0));
	}
	
	return 0;
}