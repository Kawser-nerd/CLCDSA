#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

int test(int H, int W, int T, int par) {
	vvb board(H, vb(W, 0));
	rep(i,0,H) rep(j,0,W) board[i][j] = (i + j + par) & 1;
	rep(i,0,H) rep(j,0,W) T -= board[i][j];
#define H(a, b) (0 <= a && 0 <= b && a < H && b < W && board[a][b] ? 1 : 0)
#define N(a, b) (H(a-1, b) + H(a+1, b) + H(a, b-1) + H(a, b+1))
	vi c(5);
	rep(i,0,H) rep(j,0,W) {
		if (board[i][j]) continue;
		int n = N(i, j);
		c[n]++;
	}
	int res = 0;
	rep(i,0,5) {
		int ci = min(c[i], T);
		res += i * ci;
		T -= ci;
	}
	return res;
}

int solve() {
	int H, W, T;
	cin >> H >> W >> T;
	if (2*T-1 <= H*W) return 0;
	return min(test(H, W, T, 0), test(H, W, T, 1));
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin >> N;
	rep(i,0,N) {
		printf("Case #%d: %d\n", i+1, solve());
	}
}
