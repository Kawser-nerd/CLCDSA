#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int P;
vector<vector<vi>> mem[5][4];
int rec(int a, int b, int c, int at) {
	if (a + b + c == 0) return 0;
	int& out = mem[P][at][a][b][c];
	if (out != -1) return out;
	int r = 0;
	if (a) r = max(r, rec(a-1, b, c, (at + 1) % P));
	if (b) r = max(r, rec(a, b-1, c, (at + 2) % P));
	if (c) r = max(r, rec(a, b, c-1, (at + 3) % P));
	if (at == 0) r++;
	return out = r;
}

void solve() {
	int N;
	cin >> N >> P;
	assert(P <= 4);
	vi gr(4);
	rep(i,0,N) {
		int g;
		cin >> g;
		g %= P;
		gr[g]++;
	}

	ll res = gr[0];
	gr[0] = 0;

	res += rec(gr[1], gr[2], gr[3], 0);
	cout << res << endl;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit | cin.eofbit | cin.badbit);
	cin.tie(0);
	int T;
	cin >> T;
	rep(P,2,5) rep(at,0,4)
		mem[P][at].assign(105, vector<vi>(105, vi(105, -1)));
	rep(i,0,T) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
