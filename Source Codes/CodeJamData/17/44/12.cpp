#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define P 1033
#define N 33

int n, m, C;
string a[N];
bool f[P][P];
PII pr[P][P];

PII pt[10]; int nt;
PII ps[10]; int ns;

int vt[N][N];

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void ff(int x0, int y0, int z) {
	for (int d = 0; d < 4; d ++) {
		int x = x0, y = y0;
		while (true) {
			if (x < 0 || x >= n || y < 0 || y >= m) break;
			if (a[x][y] == '#') break;
			vt[x][y] |= z;
			x += dx[d];
			y += dy[d];
		}
	}
}

int gp;
bool cv[10][10]; // [s][t]
int di[N][N];

#define INF 1000000007

void gg(int x0, int y0, int z) {
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			di[i][j] = INF;
	di[x0][y0] = 0;
	queue<PII> q;
	q.push(mp(x0, y0));
	while (!q.empty()) {
		PII _x = q.front();
		q.pop();
		int x = _x.fi;
		int y = _x.se;
		int c = vt[x][y]^(vt[x][y]&gp);
		
		if (c == 0) {
			if (di[x][y] < C) {
				for (int d = 0; d < 4; d ++) {
					int x1 = x+dx[d];
					int y1 = y+dy[d];
					if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) continue;
					if (a[x1][y1] == '#') continue;
					if (di[x1][y1] != INF) continue;
					di[x1][y1] = di[x][y]+1;
					q.push(mp(x1, y1));
				}
			}
		} else {
			for (int i = 0; i < nt; i ++)
				if ((c>>i)&1) cv[z][i] = true;
		}
	}
}

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __++) {
		cin >> m >> n >> C;
		for (int i = 0; i < n; i ++) cin >> a[i];
		nt = ns = 0;
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++) {
				if (a[i][j] == 'S') ps[ns++] = mp(i, j);
				if (a[i][j] == 'T') pt[nt++] = mp(i, j);
			}
		memset(vt, 0, sizeof vt);
		for (int i = 0; i < nt; i ++) {
			ff(pt[i].fi, pt[i].se, 1 << i);
		}
		
		memset(f, 0, sizeof f);
		f[0][0] = true;
		for (int p = 0; p < (1<<nt)-1; p ++) {
			gp = p;
			memset(cv, 0, sizeof cv);
			for (int i = 0; i < ns; i ++)
				gg(ps[i].fi, ps[i].se, i);
			for (int q = 0; q < (1<<ns)-1; q ++) if (f[p][q])
				for (int i = 0; i < ns; i ++) if (~(q>>i)&1)
					for (int j = 0; j < nt; j ++) if (~(p>>j)&1)
						if (cv[i][j]) {
							f[p|(1<<j)][q|(1<<i)] = true;
							pr[p|(1<<j)][q|(1<<i)] = mp(i, j);
						}
		}
		
		int S = 0, T = 0;
		for (int i = 0; i < (1<<nt); i ++)
			for (int j = 0; j < (1<<ns); j ++)
				if (f[i][j] && pct(i) > pct(S)) {
					S = i;
					T = j;
				}
		printf ("Case #%d: %d\n", __, pct(S));
		vector<PII> B;
		while (S != 0) {
			PII _x = pr[S][T];
			int x = _x.fi;
			int y = _x.se;
			
			B.pb(mp(x, y));
			S ^= (1<<y);
			T ^= (1<<x);
		}
		reverse(B.begin(), B.end());
		for (int i = 0; i < (int) B.size(); i ++)
			printf ("%d %d\n", B[i].fi+1, B[i].se+1);
	}
	return 0;
}