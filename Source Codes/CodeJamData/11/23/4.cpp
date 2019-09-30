#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <ppl.h>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;
using namespace Concurrency;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

critical_section criticalSection;

struct Problem {
	int problemId;
	// problem data
	int n, m;
	vector<vi> g;

	// some data
	int res;
	vi col;

	void read() {
		cin >> n >> m;
		vi from, to;
		from.resize(m);
		to.resize(m);
		g.resize(n);
		for (int i = 0; i < m; ++i) {
			cin >> from[i];
			--from[i];
		}
		for (int i = 0; i < m; ++i) {
			cin >> to[i];
			--to[i];
		}
		for (int i = 0; i < m; ++i) {
			g[from[i]].pb(to[i]);
			g[to[i]].pb(from[i]);
		}
	}

	int solve(vi v) {
		set<int> S(all(v));
		for (int i = 0; i < sz(v); ++i) {
			int x = v[i];
			for (int J = 0; J < sz(g[x]); ++J) {
				int y = g[x][J];
				if (y == v[(i + 1) % sz(v)]) continue;
				if (y == v[(i - 1 + sz(v)) % sz(v)]) continue;
				if (!S.count(y)) continue;
				vi p, q;
				int j;
				for (j = i; v[j] != y; j = (j + 1) % sz(v))
					p.pb(v[j]);
				p.pb(y);
				for (; v[j] != x;  j = (j + 1) % sz(v))
					q.pb(v[j]);
				q.pb(x);
				return min(solve(p), solve(q));
			}
		}
		return sz(v);
	}

	void mark(vi v) {
		set<int> S(all(v));
		for (int i = 0; i < sz(v); ++i) {
			int x = v[i];
			for (int J = 0; J < sz(g[x]); ++J) {
				int y = g[x][J];
				if (y == v[(i + 1) % sz(v)]) continue;
				if (y == v[(i - 1 + sz(v)) % sz(v)]) continue;
				if (!S.count(y)) continue;
				vi p, q;
				int j;
				for (j = i; v[j] != y; j = (j + 1) % sz(v))
					p.pb(v[j]);
				p.pb(y);
				for (; v[j] != x;  j = (j + 1) % sz(v))
					q.pb(v[j]);
				q.pb(x);
				int isQ = 0, isP = 0;
				for (int j = 0; j < sz(q); ++j)
					if (col[q[j]] != -1) ++isQ;
				for (int j = 0; j < sz(p); ++j)
					if (col[p[j]] != -1) ++isP;
				if (isP >= isQ) {
					mark(p);
					mark(q);
				} else {
					mark(q);
					mark(p);
				}
				return;
			}
		}
		set<int> used;
		for (int i = 0; i < sz(v); ++i)
			if (col[v[i]] != -1) used.insert(col[v[i]]);
		int ind = 0;
		set<int> u;
		for (int i = 0; i < sz(v); ++i) {
			if (col[v[i]] != -1) {
				u.insert(col[v[i]]);
				//cerr << col[v[i]] << " ";
				continue;
			}
			int IT = 0;
			while ((IT <= res && used.count(ind)) || ind == col[v[(i + 1) % sz(v)]] || ind == col[v[(i - 1 + sz(v)) % sz(v)]]) 
				ind = (ind + 1) % res, ++IT;
			col[v[i]] = ind;
			//cerr << col[v[i]] << " ";
			u.insert(col[v[i]]);
			ind = (ind + 1) % res;
		}
		//cerr << "\n";
		if (sz(u) != res) {
			cerr << "Botva " << problemId << " " << sz(u) << " " << res << "\n";
			//out();
		}
	}

	void out() {
		cout << n << " " << m << "\n";
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < sz(g[i]); ++j)
				if (g[i][j] > i) cout << i << " " << g[i][j] << "\n";
		cout << "\n";
	}

	void solve() {
		criticalSection.lock();
		cerr << "Solving case " << problemId << "\n";
		criticalSection.unlock();
		vi v;
		for (int i = 0; i < n; ++i)
			v.pb(i);
		res = solve(v);
		col = vi(n, -1);
		mark(v);
	}

	void save() {
		cout << res << "\n";
		for (int i = 0; i < n; ++i) {
			printf("%d ", col[i] + 1);
			assert(col[i] < res);
			if (col[i] >= res) cerr << "AAAA!\n";
		}
		printf("\n");
	}
};

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int nc;
	cin >> nc;
	vector<Problem> problems(nc);
	for (int it = 0; it < nc; ++it) {
		problems[it].problemId = it;
		problems[it].read();
	}

	parallel_for_each(all(problems), 
		[&](Problem& p) {
			p.solve();
		}
	);	

	for (int it = 0; it < nc; ++it) {
		printf("Case #%d: ", it + 1);
		problems[it].save();
	}
	return 0;
}
