// Chmel.Tolstiy
// Tolstsikau Aliaksei

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int dx[] = {0, -1, 1, 0, 0, -1, -1, 1, 1, 1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {0, 0, 0, 1, -1, 1, -1, 1, -1, 2, -2, 2, -2, 1, -1, 1, -1};

#define mp make_pair

int test;

char s[32][32];
int n, m;

int len[32][32][32][32];
int qi[32*32];
int qj[32*32];
int qn, ql;

int ans;

int was[32][32];

void add(pii a, pii b, pii c) {
	if (was[b.first][b.second] == 0)
		ans += len[a.first][a.second][b.first][b.second];

	was[b.first][b.second] = 1;
	
	int LEN = len[b.first][b.second][c.first][c.second];
	if (LEN == 0) return;

	for (int k = 1; k < 5; k++) {
		int x = b.first + dx[k];
		int y = b.second + dy[k];
		if (x >= 0 && x < n && y >= 0 && y < m) {
			if (len[b.first][b.second][x][y] + len[x][y][c.first][c.second] == 
				LEN) {
				add(a, mp(x, y), c);
				return;
			}
		}
	}
}

void solve() {
	cout << "Case #" << test << ": ";
	ans = 0;

	cin >> n >> m;
	
	memset(was, 0, sizeof(was));
	memset(len, 0, sizeof(len));

	for (int i = 0; i < n; i++) cin >> s[i];
	
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (s[i][j] != '.') {
		memset(len[i][j], -1, sizeof(len[i][j]));
		qn = ql = 0;
		qi[ql] = i;
		qj[ql] = j; ql++;
		len[i][j][i][j] = 0;
		while (qn < ql) {
			int x = qi[qn];
			int y = qj[qn];
			qn++;
			for (int k = 0; k < 4; k++) {
				int xx = x + dx[k+1];
				int yy = y + dy[k+1];
				if (xx >= 0 && xx < n && yy >= 0 && yy < m && s[xx][yy] != '.' && len[i][j][xx][yy] == -1) {
					len[i][j][xx][yy] = len[i][j][x][y]+1;
					qi[ql] = xx;
					qj[ql] = yy;
					ql++;
				}
			}
		}
	}
	
	int T = 0;
	set<pii> forest;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (s[i][j] == 'T') {
		T++;
		forest.insert(mp(i, j));
	}
	set<pii> have;
	have.insert(mp(0, 0));
	forest.erase(mp(0, 0));

	while (have.size() != T) {
		set<pii>::iterator ih, ifo;
		pii bh, bf;
		int LEN = 1e9;
		for (ih = have.begin(); ih != have.end(); ih++) 
			for (ifo = forest.begin(); ifo != forest.end(); ifo++) {
				pii h = *ih;
				pii f = *ifo;
				int LN = len[h.first][h.second][f.first][f.second];
				if (LN < LEN) {
					LEN = LN;
					bh = h;
					bf = f;
				}
			}
		add(bh, bh, bf);
		have.insert(bf);
		forest.erase(bf);
	}
	
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (was[i][j] == 0 && s[i][j] != '.') {
			set<pii>::iterator ih;
			int LEN = 1e9;
			for (ih = have.begin(); ih != have.end(); ih++) {
				int x = ih->first;
				int y = ih->second;
				if (len[x][y][i][j] < LEN) LEN = len[x][y][i][j];
			}
			ans += LEN;
		}
	}

	cout << ans << endl;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tests;
	cin >> tests;
	for (test = 1; test <= tests; test++)
	solve();
	fclose(stdout);
	return 0;
}