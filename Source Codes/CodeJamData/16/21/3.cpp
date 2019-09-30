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
	string str;
	cin >> str;
	map<char, int> occ;
	trav(x, str) occ[x]++;
/*
ZERO: Z
TWO: W
SIX: X
FOUR: U
EIGHT: G
ONE: O (minus FOUR)
SEVEN: S (minus SIX)
FIVE: V (minus SEVEN)
THREE: H (minus EIGHT)
NINE: N/2 (minus ONE, SEVEN)
*/
	int res[10];
	res[0] = occ['Z'];
	res[2] = occ['W'];
	res[6] = occ['X'];
	res[4] = occ['U'];
	res[8] = occ['G'];
	res[1] = occ['O'] - res[4] - res[2] - res[0];
	res[7] = occ['S'] - res[6];
	res[5] = occ['V'] - res[7];
	res[3] = occ['H'] - res[8];
	res[9] = (occ['N'] - res[1] - res[7]) / 2;
	rep(i,0,10) rep(j,0,res[i]) cout << i;
	cout << endl;
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
