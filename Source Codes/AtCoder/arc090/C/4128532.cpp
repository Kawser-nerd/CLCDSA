#ifndef ___CLASS_MODINT
#define ___CLASS_MODINT

#include <cstdint>

template<std::uint32_t mod>
class modint {
private:
	std::uint32_t n;
public:
	modint() : n(0) {};
	modint(std::uint64_t n_) : n(n_ % mod) {};
	bool operator==(const modint& m) const { return n == m.n; }
	bool operator!=(const modint& m) const { return n != m.n; }
	std::uint32_t get() const { return n; }
	modint& operator+=(const modint& m) { n += m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator-=(const modint& m) { n += mod - m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator*=(const modint& m) { n = std::uint64_t(n) * m.n % mod; return *this; }
	modint operator+(const modint& m) const { return modint(*this) += m; }
	modint operator-(const modint& m) const { return modint(*this) -= m; }
	modint operator*(const modint& m) const { return modint(*this) *= m; }
	modint binpow(std::uint64_t b) const {
		modint ans = 1, m = modint(*this);
		while (b) {
			if (b & 1) ans *= m;
			m *= m;
			b >>= 1;
		}
		return ans;
	}
	modint inv() { return (*this).binpow(mod - 2); }
	modint sqr() { return (*this).operator*(n); }
};

#endif // ___CLASS_MODINT

#include <queue>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;
const long long inf = 1LL << 61;
using modulo = modint<1000000007>;
struct edge {
	int to, cost;
};
struct state {
	int pos; long long cost;
};
bool operator>(const state& s1, const state& s2) {
	return s1.cost > s2.cost;
}
struct answer {
	vector<long long> dist;
	vector<modulo> comb;
};
answer shortest_path(int src, vector<vector<edge> > &G) {
	int N = G.size();
	vector<long long> dist(N, inf); dist[src] = 0;
	vector<modulo> comb(N); comb[src] = 1;
	vector<bool> vis(N);
	priority_queue<state, vector<state>, greater<state> > que;
	que.push(state{ src, 0 });
	while (!que.empty()) {
		state u = que.top(); que.pop();
		if (vis[u.pos]) continue;
		vis[u.pos] = true;
		for (edge e : G[u.pos]) {
			if (dist[e.to] > dist[u.pos] + e.cost) {
				dist[e.to] = dist[u.pos] + e.cost;
				comb[e.to] = 0;
				que.push(state{ e.to, dist[e.to] });
			}
			if (dist[e.to] == dist[u.pos] + e.cost) {
				comb[e.to] += comb[u.pos];
			}
		}
	}
	return answer{ dist, comb };
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M, S, T;
	cin >> N >> M >> S >> T; --S, --T;
	vector<vector<edge> > G(N);
	for (int i = 0; i < M; ++i) {
		int U, V, D;
		cin >> U >> V >> D; --U, --V;
		G[U].push_back(edge{ V, D });
		G[V].push_back(edge{ U, D });
	}
	answer TKHS = shortest_path(S, G);
	answer AOKI = shortest_path(T, G);
	modulo ans = (TKHS.comb[T]).sqr();
	long long d = TKHS.dist[T];
	for (int i = 0; i < N; ++i) {
		if (TKHS.dist[i] == AOKI.dist[i] && TKHS.dist[i] + AOKI.dist[i] == d) {
			ans -= (TKHS.comb[i] * AOKI.comb[i]).sqr();
		}
		for (edge e : G[i]) {
			if (TKHS.dist[i] * 2 < d && AOKI.dist[e.to] * 2 < d && TKHS.dist[i] + AOKI.dist[e.to] + e.cost == d) {
				ans -= (TKHS.comb[i] * AOKI.comb[e.to]).sqr();
			}
		}
	}
	cout << ans.get() << endl;
	return 0;
}