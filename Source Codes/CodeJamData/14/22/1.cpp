#include <cstdio>
#include <numeric>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int was[31][2][2][2];
ll res[31][2][2][2];
int x[31];
int y[31];
int z[31];
int a, b, k;

ll go (int i, int a, int b, int c) {
	if (i == 31) re 1;
	if (was[i][a][b][c]) re res[i][a][b][c];
	was[i][a][b][c] = 1;
	ll cur = 0;
	for (int p = 0; p < 2; p++)
		if (p <= x[i] || a)
			for (int q = 0; q < 2; q++)
				if (q <= y[i] || b) {
					int r = p & q;
					if (r <= z[i] || c) 
						cur += go (i + 1, a | int (p < x[i]), b | int (q < y[i]), c | int (r < z[i]));
				}
	re res[i][a][b][c] = cur;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> a >> b >> k; a--; b--; k--;
		for (int i = 0; i <= 30; i++) {
			x[30 - i] = (a >> i) & 1;
			y[30 - i] = (b >> i) & 1;
			z[30 - i] = (k >> i) & 1;
		}
		memset (was, 0, sizeof (was));
		cout << "Case #" << it << ": " << go (0, 0, 0, 0);
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}