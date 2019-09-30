#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node {
	int low, high;
};

int solve() {
	int N, D;
	cin >> N >> D;
	ll S0, AS, CS, RS;
	ll M0, AM, CM, RM;
	cin >> S0 >> AS >> CS >> RS;
	cin >> M0 >> AM >> CM >> RM;
	vector<int> s(N), m(N);
	s[0] = (int)S0;
	m[0] = -1;
	rep(i,1,N) {
		S0 = (S0 * AS + CS) % RS;
		M0 = (M0 * AM + CM) % RM;
		s[i] = (int)S0;
		m[i] = (int)(M0 % i);
	}
	
	vector<Node> nodes(N);
	rep(i,0,N) {
		nodes[i].low = s[i] - D;
		nodes[i].high = s[i];
	}

	rep(i,1,N) {
		nodes[i].low = max(nodes[i].low, nodes[m[i]].low);
		nodes[i].high = min(nodes[i].high, nodes[m[i]].high);
	}

	vector<pii> ev;
	rep(i,0,N) {
		if (nodes[i].low <= nodes[i].high) {
			ev.emplace_back(nodes[i].low, -1);
			ev.emplace_back(nodes[i].high, 1);
		}
	}
	sort(all(ev));

	int res = 0, cur = 0;
	trav(pa, ev) {
		res = max(res, cur);
		cur -= pa.second;
	}

	return res;
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin >> N;
	rep(i,0,N) {
		printf("Case #%d: %d\n", i+1, solve());
	}
}
