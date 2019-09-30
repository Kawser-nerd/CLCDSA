#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int solve() {
	int H, W;
	cin >> H >> W;
	vector<string> board(H);
	vector<vi> u(H, vi(W, 0));
	rep(i,0,H)
		cin >> board[i];
	int ch = 0;
	rep(i,0,H) {
		rep(j,0,W) {
			if (board[i][j] != '.') {
				if (board[i][j] == '<') ch++;
				u[i][j]++;
				break;
			}
		}
		rep(jj,0,W) {
			int j = W - 1 - jj;
			if (board[i][j] != '.') {
				if (board[i][j] == '>') ch++;
				u[i][j]++;
				break;
			}
		}
	}

	rep(j,0,W) {
		rep(i,0,H) {
			if (board[i][j] != '.') {
				if (board[i][j] == '^') ch++;
				u[i][j]++;
				break;
			}
		}
		rep(ii,0,H) {
			int i = H - 1 - ii;
			if (board[i][j] != '.') {
				if (board[i][j] == 'v') ch++;
				u[i][j]++;
				break;
			}
		}
	}

	trav(uu, u) trav(uuu, uu) if (uuu == 4) return -1;

	return ch;
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin >> N;
	rep(i,0,N) {
		int x = solve();
		if (x == -1)
			printf("Case #%d: IMPOSSIBLE\n", i+1);
		else
			printf("Case #%d: %d\n", i+1, x);
	}
}
