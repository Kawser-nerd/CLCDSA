#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 82
#define INF 1000000007

int f[N][N][N][N];
bool st[N][N][N][N];
int n,c[N];
vector<int> A[N];
bool v[N][N][N];

typedef vector<int>::iterator VIT;
bool u[N];

void ff(int z, int x) {
	u[x] = 1;
	for (int i = 0; i < n; i ++) v[z][x][i] = u[i];
	for (VIT i = A[x].begin(); i != A[x].end(); i ++) 
		if (!u[*i]) ff(z,*i);
	u[x] = 0;
}

int ff(int x0, int y0, int x1, int y1) {
	int &S = f[x0][y0][x1][y1];
	if (S != -INF)
		return S;
	if (st[x0][y0][x1][y1]) {
		if (st[x1][y1][x0][y0]) return S = 0;
		return S=-ff(x1,y1,x0,y0);
	}
	for (VIT i = A[y0].begin(); i != A[y0].end(); i ++) 
		if (!v[x0][y0][*i] && !(v[x1][y1][y0] && v[x1][y1][*i])) {
			int p = 0;
			if (!v[x1][y1][*i]) p = c[*i];
			S = max(S, p-ff(x1,y1,x0,*i));
		}
	return S;
}

int main()
{
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> c[i];
		for (int i = 0; i < n; i ++) A[i].clear();
		for (int i = 1; i < n; i ++) {
			int x = i-1,y;
			cin >> y; y --;
			A[x].pb(y), A[y].pb(x);
		}
		memset(v,0,sizeof v);
		for (int i = 0; i < n; i ++) {
			memset(u,0,sizeof u);
			ff(i,i);
		}
		for (int i = 0; i < n; i ++) 
			for (int j = 0; j < n; j ++) 
				for (int k = 0; k < n; k ++) 
					for (int l = 0; l < n; l ++) {
						f[i][j][k][l] = -INF; 
					}
		memset(st,0,sizeof st);
		for (int x0 = 0; x0 < n; x0 ++) 
			for (int y0 = 0; y0 < n; y0 ++)
				for (int x1 = 0; x1 < n; x1 ++)
					for (int y1 = 0; y1 < n; y1 ++) {
						bool &F = st[x0][y0][x1][y1];
						F = 1;
						for (VIT i = A[y0].begin(); i != A[y0].end(); i ++) 
							if (!v[x0][y0][*i] && !(v[x1][y1][y0] && v[x1][y1][*i])) {
								F = 0; break;
							}
					}
		int S = -INF;
		for (int i = 0; i < n; i ++) {
			int T = INF;
			for (int j = 0; j < n; j ++) {
				int z = c[i];
				if (i != j) z -= c[j];
				T = min(T, z+ff(i,i,j,j));
			}
			S = max(S, T);
		}
		printf ("Case #%d: %d\n",__, S);
	}
	return 0;
}