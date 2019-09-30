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

const int mod = 1000003;
const int di[4] = {1, 1, 0, 1};
const int dj[4] = {0, -1, 1, 1};

int n;
int m;
int cnt[100][100];
int t[100][100];
int was[100][100];
vii v[100][100];
char w[101][101];
int s, sv;

int go (int i, int j) {
	was[i][j] = 1;
	s++;
	for (int k = 0; k < sz (v[i][j]); k++) {
		int ni = v[i][j][k].fi;
		int nj = v[i][j][k].se;
		if (!was[ni][nj]) go (ni, nj);
		sv++;
	}
	re 0;
}
                                                   
int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {

		scanf ("%d%d", &n, &m);
		gets (w[0]);
		for (int i = 0; i < n; i++)
			gets (w[i]);
		for (int i = 0; i < n; i++)	
			for (int j = 0; j < m; j++)
				v[i][j].clear ();
		for (int i = 0; i < n; i++)	
			for (int j = 0; j < m; j++)
				if (w[i][j] == '|')
					t[i][j] = 0;
				else
				if (w[i][j] == '/')	
					t[i][j] = 1;
				else
				if (w[i][j] == '-')
					t[i][j] = 2;
				else
				if (w[i][j] = '\\')	
					t[i][j] = 3;
		for (int p = 0; p < n; p++)
			for (int q = 0; q < m; q++) {
				int np = p + di[t[p][q]]; 
				int nq = q + dj[t[p][q]]; 
				int sp = p - di[t[p][q]]; 
				int sq = q - dj[t[p][q]]; 
				np = (np + n) % n;
				nq = (nq + m) % m;
				sp = (sp + n) % n;
				sq = (sq + m) % m;
				v[np][nq].pb (make_pair (sp, sq));
				v[sp][sq].pb (make_pair (np, nq));
			}	
		int ans = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				was[i][j] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!was[i][j]) {
					s = sv = 0;
					go (i, j);
					sv /= 2;
					if (s != sv) ans = 0; else ans = (ans * 2) % mod;
				}
		printf ("Case #%d: %d\n", it, ans);
	}
	return 0;
}