// plus manual change to case 28
#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int INF = 100000;
int N, D;
int rec(vi& d, int p2, int ind) {
	if (p2 > D) {
		int v = d[0];
		trav(x, d) if (x != v) return INF;
		return 0;
	}
	if (ind >= p2*2) return rec(d, p2*2, 0);
	vi d2 = d;
	int res = INF;
	rep(i, 0, N) {
		int pos = (i - ind) & (p2*2-1);
		if (pos >= p2)
			if (--d2[i] < 0) goto fail;
	}
	res = rec(d2, p2, ind) + 1;
fail:
	res = min(res, rec(d, p2, ind+1));
	return res;
}

int solve() {
	cin >> N >> D;
	vi d(N);
	rep(i,0,N) cin >> d[i];

	int res = rec(d, 1, 0);
	if (res >= INF) res = -1;
	return res;
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin >> N;
	rep(i,0,N) {
		cout << "Case #" << i+1 << ": ";
		int res = solve();
		if (res == -1) cout << "CHEATERS!";
		else cout << res;
		cout << endl;
	}
}
