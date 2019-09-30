#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

void solve() {
	int N, L;
	cin >> N >> L;
	vector<string> good(N);
	rep(i,0,N) cin >> good[i];
	string bad;
	cin >> bad;
	if (find(all(good), bad) != good.end()) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	/*
	string a = string(L-1, '?');
	if (L == 1) a += '0';
	string b = "10?";
	rep(i,0,L-1) b += "10";
	*/
	string a, b;
	trav(c, bad) {
		char op = (char)(c ^ 1);
		a += op;
		a += '?';
		b += op;
		b += c;
	}
	b.erase(b.end()-1);
	assert(sz(a) + sz(b) <= 200);
	cout << a << ' ' << b << endl;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	rep(i,0,N) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
