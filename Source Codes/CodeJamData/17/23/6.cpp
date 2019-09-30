#include <bits/stdc++.h>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const string& x, char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }

template<class T> void chmin(T& a, const T& b) { if (a > b) a = b; }
template<class T> void chmax(T& a, const T& b) { if (a < b) a = b; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
ll mod_pow(ll a, ll n, ll mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }

struct dijkstra {
	using cost_type = double;

	struct edge {
		int to;
		cost_type cost;
		edge() {}
		edge(int to, cost_type cost) : to(to), cost(cost) {}
	};
	typedef pair<cost_type, int> P;

	static void run(vector<vector<edge> >& edges, vector<cost_type>& cost_table, int s, vector<int>* _prev = NULL) {
		//init
		cost_table.resize((int)edges.size());
		fill(cost_table.begin(), cost_table.end(), numeric_limits<cost_type>::max() / 3);
		if (_prev) _prev->resize(edges.size());
		if (_prev) fill(_prev->begin(), _prev->end(), -1);

		priority_queue<P, vector<P>, greater<P> > q;
		q.push(P(0, s));
		cost_table[s] = 0;

		while (!q.empty()) {
			P p = q.top(); q.pop();
			int v = p.second;
			if (cost_table[v] < p.first) continue;
			for (const auto& e : edges[v]) {
				if (cost_table[e.to] > cost_table[v] + e.cost) {
					cost_table[e.to] = cost_table[v] + e.cost;
					if (_prev) (*_prev)[e.to] = v;
					q.push(P(cost_table[e.to], e.to));
				}
			}
		}
	}
};

double e[100], s[100];
double d[100][100];

vector<double> solve() {
	int n, q; reader(n, q);
	FOR(i, n) {
		scanf("%lf%lf",e+i,s+i);
	}
	FOR(i, n) FOR(j, n) {
		scanf("%lf", d[i] + j);
		if (d[i][j] == -1) d[i][j] = 1e20;
	}
	FOR(i, n) d[i][i] = 0;
	FOR(k, n) FOR(i, n) FOR(j, n) {
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}


	vector<vector<dijkstra::edge>> g(n);
	FOR(i, n) FOR(j, n) {
		if (d[i][j] <= e[i]) {
			g[i].emplace_back(j, d[i][j] / s[i]);
		}
	}

	vector<double> ans;
	FOR(i, q) {
		int s, t; reader(s, t); s--; t--;

		vector<double> cost_table;
		dijkstra::run(g, cost_table, s);
		ans.push_back(cost_table[t]);
	}

	return ans;
}

int main() {
	int t; reader(t);
	FOR(i, t) {
		auto ans = solve();
		printf("Case #%d: ", i + 1);
		FOR(i, sz(ans)) printf("%.10lf%c", ans[i], i == sz(ans)-1? '\n': ' ');
	}

	return 0;
}