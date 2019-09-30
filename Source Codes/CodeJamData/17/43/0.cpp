#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define Min(...) min({__VA_ARGS__})
#define Max(...) max({__VA_ARGS__})
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
static inline ll sgn(ll x) { return (x>0)-(x<0); }
static inline bool vowel(char c) { c = (char)tolower(c); return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y'; }
static inline vi rvi(int N) { vi res(N); rep(i,0,N) cin >> res[i]; return res; }
static inline int ri() { int N; cin >> N; return N; }
static inline void pvi(const vi& r) { trav(it,r) cout << it << " "; cout << endl; }
template<class S, class T> static inline void smax(S& s, const T& t) { if (t > s) s = t; }
template<class S, class T> static inline void smin(S& s, const T& t) { if (t < s) s = t; }
template<class S> static inline void in(S& s) { cin >> s; }
template<class S> static inline void ut(const S& s) { cout << s << " "; }
static inline void nl() { cout << endl; }

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

pair<bool, vector<pii>> go(int r, int c, const vector<string>& G, int dir) {
	set<pii> covered;
	auto rec = [&G,&covered](int r, int c, int dir) {
		while (true) {
			r += dr[dir];
			c += dc[dir];
			
			if (r < 0 || r >= sz(G)) return true;
			if (c < 0 || c >= sz(G[0])) return true;
			if (G[r][c] == '#') return true;
			if (G[r][c] == '|' || G[r][c] == '-') return false;
			covered.emplace(r, c);

			if (G[r][c] == '/') {
				if (dir == 0) dir = 3;
				else if (dir == 1) dir = 2;
				else if (dir == 2) dir = 1;
				else if (dir == 3) dir = 0;
			}
			if (G[r][c] == '\\') {
				if (dir == 0) dir = 1;
				else if (dir == 1) dir = 0;
				else if (dir == 2) dir = 3;
				else if (dir == 3) dir = 2;
			}
		}
	};
	if (!rec(r, c, dir) || !rec(r, c, dir+2)) return make_pair(false, vector<pii>());

	vector<pii> res(all(covered));
	return make_pair(true, res);
}

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int add_var() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void add_clause(int aind, bool aval, int bind, bool bval) {
		int a = 2*aind + aval, b = 2*bind + bval;
		gr[a^1].push_back(b);
		gr[b^1].push_back(a);
	}
	void set_value(int index, bool value) { // (optional)
		add_clause(index, value, index, value);
	}

	void at_most_one(const vi& li, bool val=1) { // (optional)
		if (sz(li) <= 1) return;
		int cur = li[0];
		rep(i,2,sz(li)) {
			int next = add_var();
			add_clause(cur, !val, li[i], !val);
			add_clause(cur, !val, next, val);
			add_clause(li[i], !val, next, val);
			cur = next;
		}
		add_clause(cur, !val, li[1], !val);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		trav(e, gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		++time;
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = time;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

void solve() {
	int R, C;
	cin >> R >> C;
	vector<string> G(R);
	rep(i,0,R) cin >> G[i];

	vector<vector<vector<pair<int, bool>>>> covered(R, vector<vector<pair<int, bool>>>(C));
	TwoSat ts(R * C);
	rep(i,0,R) rep(j,0,C) {
		if (G[i][j] == '|' || G[i][j] == '-') {
			pair<bool, vector<pii>> hor = go(i, j, G, 0);
			pair<bool, vector<pii>> vert = go(i, j, G, 1);

			if (hor.first) {
				trav(it, hor.second) {
					covered[it.first][it.second].emplace_back(i * C + j, true);
				}
			} else ts.set_value(i * C + j, false);
			if (vert.first) {
				trav(it, vert.second) {
					covered[it.first][it.second].emplace_back(i * C + j, false);
				}
			} else ts.set_value(i * C + j, true);
		}
	}
	rep(i,0,R) rep(j,0,C) {
		if (G[i][j] == '.') {
			assert(sz(covered[i][j]) <= 2);
			if (covered[i][j].empty()) {
				cout << "IMPOSSIBLE" << endl;
				return;
			}
			if (sz(covered[i][j]) == 1) ts.set_value(covered[i][j][0].first, covered[i][j][0].second);
			else {
				pair<int, bool> a = covered[i][j][0];
				pair<int, bool> b = covered[i][j][1];
				ts.add_clause(a.first, a.second, b.first, b.second);
			}
		}
	}
	if (!ts.solve()) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	rep(i,0,R) rep(j,0,C) {
		if (G[i][j] == '|' || G[i][j] == '-') {
			if (ts.values[i * C + j]) G[i][j] = '-';
			else G[i][j] = '|';
		}
	}
	cout << "POSSIBLE" << endl;
	rep(i,0,R) cout << G[i] << endl;
}

signed main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int TC;
	cin >> TC;
	rep(i,0,TC) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
