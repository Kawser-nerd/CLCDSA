#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T a) {return a > 0 ? a : (-a); }
template<class T> T sqr(T a) {return a * a; }

using namespace std;

const int MAXN = 1000;
int n, m;
vector<int> sm[MAXN];

pair<int, int> dst[MAXN][MAXN];//cur;pred
set<pair<pair<int, int>, pair<int, int> > > q;
int opt_dst[MAXN];

int new_threat(int pred, int cur, int next) {
	int i = 0;
	int j = 0;
	int ans = 0;
	for (int k = 0; k < sz(sm[next]); ++k) {
		while (i < sz(sm[pred]) && sm[pred][i] < sm[next][k]) ++i;
		while (j < sz(sm[cur]) && sm[cur][j] < sm[next][k]) ++j; 
		if (i < sz(sm[pred]) && sm[pred][i] == sm[next][k]) continue;
		if (j < sz(sm[cur]) && sm[cur][j] == sm[next][k]) continue;
		if (sm[next][k] == pred || sm[next][k] == cur) continue;
		++ans;
	}
	return ans - 1;
}

void update(pair<int, int> what, pair<int, int> value) {
	if (value.first > opt_dst[what.first]) {
		return;
	}
	else 
		opt_dst[what.first] = value.first;
	if (dst[what.first][what.second] > value) {
		q.erase(mp(dst[what.first][what.second], what));
		dst[what.first][what.second] = value;
		q.insert(mp(dst[what.first][what.second], what));
	}
}

void solve(int testnum) {
	cerr << testnum << endl;
	cin >> n >> m;
	++n;
//	cout << n << " " << m << endl;
	for (int i = 0; i < n; ++i) {
		sm[i].clear();
		opt_dst[i] = MAXN;
	}
	for (int i = 0; i < m; ++i) {
		string s;
		int a, b;
		cin >> s;
		sscanf(s.c_str(), "%d,%d", &a, &b);
//		cerr << a << " " << b << "\n";
		sm[a].pb(b);
		sm[b].pb(a);
	}
	q.clear();
	for (int i = 0; i < n; ++i) sort(all(sm[i]));
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dst[i][j] = make_pair(MAXN, 0);
	pair<int, int> ans = make_pair(MAXN, 0);
	update(mp(0, n - 1), mp(0, -sz(sm[0])));
	while (!q.empty()) {
		pair<int, int> what = q.begin()->second;
		pair<int, int> dst = q.begin()->first;
//		printf("cur = %d, pred = %d; dst = %d, threats = %d\n", what.first, what.second, dst.first, -dst.second);
		q.erase(q.begin());
		for (int i = 0; i < sz(sm[what.first]); ++i) {
			int u = sm[what.first][i];
			if (u == 1) ans = min(ans, dst);
			update(mp(u, what.first), mp(dst.first + 1, dst.second - new_threat(what.second, what.first, u)));
		}
	}
	printf("Case #%d: %d %d\n", testnum, ans.first, -ans.second);
//	cerr << endl;

}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) solve(i + 1);
	return 0;
}
