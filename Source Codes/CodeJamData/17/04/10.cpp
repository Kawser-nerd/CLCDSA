#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pct __builtin_popcount

#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (__typeof((c).begin()) i=((c).begin()); i!=((c).end()); i++)

#define N 210
int n, m;
bool vr[N], vc[N], vp[N], vm[N];
int a[N][N];
int b[N][N];

bool w[N][N], v[N];
int r[N];
int c;

bool ff(int x) {
	for (int i = 0; i < c; i ++)
		if (w[x][i] && !v[i]) {
			v[i] = true;
			if (r[i] == -1 || ff(r[i])) {
				r[i] = x;
				return true;
			}
		}
	return false;
}

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n >> m;
		memset(vr, 0, sizeof vr);
		memset(vc, 0, sizeof vc);
		memset(vp, 0, sizeof vp);
		memset(vm, 0, sizeof vm);
		memset(a, 0, sizeof a);
		int S = 0;
		while (m--) {
			string s;
			cin >> s;
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			if (s[0] != '+') {
				vr[x] = vc[y] = true;
				a[x][y] |= 1;
				S++;
			}
			if (s[0] != 'x') {
				vp[x+y] = vm[x-y+(n-1)] = true;
				a[x][y] |= 2;
				S++;
			}
		}
		memset(b, 0, sizeof b);
		
		memset(w, 0, sizeof w);
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				if (!vr[i] && !vc[j]) w[i][j] = true;
		
		memset(r, -1, sizeof r);
		c = n;
		for (int i = 0; i < c; i ++) {
			memset(v, 0, sizeof v);
			ff(i);
		}
		
		for (int i = 0; i < n; i ++)
			if (r[i] != -1) {
				b[r[i]][i] |= 1;
				S++;
			}
		memset(w, 0, sizeof w);
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				if (!vp[i+j] && !vm[i-j+(n-1)]) w[i+j][i-j+(n-1)] = true;

		memset(r, -1, sizeof r);
		c = n*2-1;
		for (int i = 0; i < c; i ++) {
			memset(v, 0, sizeof v);
			ff(i);
		}
		
		for (int i = 0; i < c; i ++)
			if (r[i] != -1) {
				b[(r[i]+i-(n-1))/2][(r[i]-i+(n-1))/2] |= 2;
				S++;
			}
		
		vector<pair<char, PII> > A;
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				if (b[i][j]) {
					int u = a[i][j] | b[i][j];
					assert(a[i][j] != u);
					A.pb(mp("x+o"[u-1], mp(i, j)));
				}
		
		printf ("Case #%d: %d %d\n", __, S, (int) A.size());
		for (int i = 0; i < (int) A.size(); i ++)
			printf ("%c %d %d\n", A[i].fi, A[i].se.fi+1, A[i].se.se+1);
	}
	return 0;
}
