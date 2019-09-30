#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 55
#define M N*N*2
const string win = "POSSIBLE";
const string lose = "IMPOSSIBLE";

int n, m;
string a[N];

int f1[N][N]; // f1 = -
int f2[N][N]; // f2 = |

PII A[M]; int p;
vector<pair<PII, int> > c;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

bool can(int x, int y, int d) {
	x += dx[d];
	y += dy[d];
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	if (a[x][y] == '#') return true;
	if (a[x][y] == '|' || a[x][y] == '-') return false;
	if (a[x][y] == '.') {
		if (d == 0 || d == 2) c.pb(mp(mp(x, y), 0));
		else c.pb(mp(mp(x, y), 1));
	}
	if (a[x][y] == '\\') {
		if (d == 0) d = 3; else
		if (d == 1) d = 2; else
		if (d == 2) d = 1; else
		if (d == 3) d = 0;
	}
	if (a[x][y] == '/') {
		if (d == 0) d = 1; else
		if (d == 1) d = 0; else
		if (d == 2) d = 3; else
		if (d == 3) d = 2;
	}
	return can(x, y, d);
}

vector<int> C[M], IC[M];

void addEdge(int x, int y) {
	C[x].pb(y);
	IC[y].pb(x);
}

void setTrue(int x) {
	addEdge(x^1, x);
}

bool v[M];
int st[M], sn, cc[M], co, ch[M];
int S[M];

void ff1(int x) {
	v[x] = 1;
	for (int i = 0; i < (int) C[x].size(); i ++)
		if (!v[C[x][i]]) ff1(C[x][i]);
	st[sn++] = x;
}

void ff2(int x) {
	v[x] = 0;
	cc[x] = co;
	for (int i = 0; i < (int) IC[x].size(); i ++)
		if (v[IC[x][i]]) ff2(IC[x][i]);
}

void gg(int x, int c) {
	S[x] = c;
	if (S[x^1] == -1) gg(x^1, 1-c);
	if (c == 1) {
		for (int i = 0; i < (int) C[x].size(); i ++)
			if (S[C[x][i]] == -1) gg(C[x][i], 1);
	} else {
		for (int i = 0; i < (int) IC[x].size(); i ++)
			if (S[IC[x][i]] == -1) gg(IC[x][i], 0);
	}
}

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n >> m;
		for (int i = 0; i < n; i ++) cin >> a[i];
		memset(f1, -1, sizeof f1);
		memset(f2, -1, sizeof f2);
		p = 0;
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
				if (a[i][j] == '|' || a[i][j] == '-')
					A[p++] = mp(i, j);
		for (int i = 0; i < p*2; i ++) {
			C[i].clear(); IC[i].clear();
		}
		for (int i = 0; i < p; i ++) {
			// up & dn
			c.clear();
			if (can(A[i].fi, A[i].se, 0) && can(A[i].fi, A[i].se, 2)) {
				for (int j = 0; j < (int) c.size(); j ++)
					if (c[j].se == 1) f1[c[j].fi.fi][c[j].fi.se] = i*2;
					else f2[c[j].fi.fi][c[j].fi.se] = i*2;
			} else {
				setTrue(i*2+1);
			}
			
			// ri & le
			c.clear();
			if (can(A[i].fi, A[i].se, 1) && can(A[i].fi, A[i].se, 3)) {
				for (int j = 0; j < (int) c.size(); j ++)
					if (c[j].se == 1) f1[c[j].fi.fi][c[j].fi.se] = i*2+1;
					else f2[c[j].fi.fi][c[j].fi.se] = i*2+1;
			} else {
				setTrue(i*2);
			}
		}
		bool F = true;
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
				if (a[i][j] == '.') {
					if (f1[i][j] == -1) {
						if (f2[i][j] == -1) F = false; else {
							setTrue(f2[i][j]);
						}
					} else {
						if (f2[i][j] == -1) {
							setTrue(f1[i][j]);
						} else {
							addEdge(f1[i][j]^1, f2[i][j]);
							addEdge(f2[i][j]^1, f1[i][j]);
						}
					}
				}
		sn = 0;
		for (int i = 0; i < p*2; i ++)
			if (!v[i]) ff1(i);
		co = 0;
		for (int i = sn-1; i >= 0; i --)
			if (v[st[i]]) {
				ch[co] = st[i];
				ff2(st[i]);
				co++;
			}
		for (int i = 0; i < p*2; i ++)
			if (cc[i] == cc[i^1]) F = false;
		printf ("Case #%d: ", __);
		if (!F) {
			cout << lose << endl;
			continue;
		}
		cout << win << endl;
		
		memset(S, -1, sizeof S);
		for (int i = co-1; i >= 0; i --) {
			if (S[ch[i]] == -1) gg(ch[i], 1);
		}
		
		for (int i = 0; i < p*2; i ++)
			if (S[i] == 1) {
				if (i%2 == 0) a[A[i/2].fi][A[i/2].se] = '|';
				else a[A[i/2].fi][A[i/2].se] = '-';
			}
		for (int i = 0; i < n; i ++)
			cout << a[i] << endl;
	}
	return 0;
}