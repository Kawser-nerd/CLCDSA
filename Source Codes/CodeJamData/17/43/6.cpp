#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

	void set_value(int index) {
		if (index >= 0) set_value(index, true);
		else set_value(~index, false);
	}

	void add_clause(int a, int b) {
		bool av = (a >= 0), bv = (b >= 0);
		if (a < 0) a = ~a;
		if (b < 0) b = ~b;
		add_clause(a, av, b, bv);
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

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
};

bool solve() {
	int R, C;
	cin >> R >> C;
	vector<string> board(R);
	rep(i,0,R) cin >> board[i];
	UF uf(R*(C+1) + C*(R+1));
	vi beam(R*(C+1) + C*(R+1)), varFor = beam;
	auto left = [&](int i, int j) { return i * (C+1) + j; };
	auto right = [&](int i, int j) { return i * (C+1) + j+1; };
	auto up = [&](int i, int j) { return i * C + j + R*(C+1); };
	auto down = [&](int i, int j) { return (i+1) * C + j + R*(C+1); };
	rep(i,0,R) rep(j,0,C) {
		char c = board[i][j];
		if (c == '.') {
			uf.join(up(i,j), down(i,j));
			uf.join(left(i,j), right(i,j));
		}
		else if (c == '/') {
			uf.join(up(i,j), left(i,j));
			uf.join(right(i,j), down(i,j));
		}
		else if (c == '\\') {
			uf.join(up(i,j), right(i,j));
			uf.join(down(i,j), left(i,j));
		}
	}

	vector<pii> beams;
	int beamid = 0;
	rep(i,0,R) rep(j,0,C) {
		if (board[i][j] == '-' || board[i][j] == '|') {
			beam[uf.find(up(i,j))]++;
			beam[uf.find(left(i,j))]++;
			beam[uf.find(down(i,j))]++;
			beam[uf.find(right(i,j))]++;
			varFor[uf.find(up(i,j))] = beamid;
			varFor[uf.find(left(i,j))] = ~beamid;
			varFor[uf.find(down(i,j))] = beamid;
			varFor[uf.find(right(i,j))] = ~beamid;
			beamid++;
			beams.emplace_back(i, j);
		}
	}

	TwoSat ts(beamid);

	beamid = 0;
	rep(i,0,R) rep(j,0,C) {
		if (board[i][j] == '-' || board[i][j] == '|') {
			if (beam[uf.find(up(i,j))] != 1 || beam[uf.find(down(i,j))] != 1) {
				ts.set_value(beamid, false);
			}
			if (beam[uf.find(left(i,j))] != 1 || beam[uf.find(right(i,j))] != 1) {
				ts.set_value(beamid, true);
			}
			beamid++;
		}
	}

	rep(i,0,R) rep(j,0,C) {
		if (board[i][j] == '.') {
			bool hasUp = (beam[uf.find(up(i,j))] == 1);
			bool hasLeft = (beam[uf.find(left(i,j))] == 1);
			int idUp = varFor[uf.find(up(i,j))];
			int idLeft = varFor[uf.find(left(i,j))];
			if (!hasUp && !hasLeft) return false;
			if (hasUp && hasLeft) {
				ts.add_clause(idUp, idLeft);
			}
			else if (hasUp)
				ts.set_value(idUp);
			else
				ts.set_value(idLeft);
		}
	}

	if (!ts.solve()) return false;
	rep(i,0,beamid) {
		bool b = ts.values[i];
		board[beams[i].first][beams[i].second] = b ? '|' : '-';
	}

	cout << "POSSIBLE" << endl;
	rep(i,0,R) cout << board[i] << endl;
	return true;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit | cin.eofbit | cin.badbit);
	cin.tie(0);
	int T;
	cin >> T;
	rep(i,0,T) {
		cout << "Case #" << i+1 << ": ";
		if (!solve()) {
			cout << "IMPOSSIBLE" << endl;
		}
	}
}
