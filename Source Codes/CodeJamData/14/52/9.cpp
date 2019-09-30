#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MAX_N = 100 + 10;
const int MAX_SHOT = 2000 + 10;

int dp[MAX_N][MAX_SHOT]; //[0,i) are dead
int P, Q, N;
int G[MAX_N], H[MAX_N];

int get(int h, int each) {
	if (h % each == 0)
		return h / each;
	return h / each + 1;
}

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		printf("Case #%d: ", nc);
		cin >> P >> Q >> N;
		for (int i = 0; i < N; ++i) {
			cin >> H[i] >> G[i];
		}
		memset(dp, -1, sizeof dp);
		dp[0][1] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < MAX_SHOT; ++j) {
				int c = dp[i][j];
				if (c == -1)
					continue;
				for (int wait = 0;; ++wait) {
					if (wait * Q < H[i]) {
						//we shot it at the end!
						int need = get(H[i] - wait * Q, P);
						if (wait + j >= need) {
							int nj = min(MAX_SHOT - 1, wait + j - need);
							dp[i + 1][nj] = max(dp[i + 1][nj], c + G[i]);
						}
					} else { //we lose at it T_T
						int nj = min(MAX_SHOT - 1, wait + j);
						dp[i + 1][nj] = max(dp[i + 1][nj], c);
						break;
					}
				}
			}
		}
		int ans = *max_element(dp[N], dp[N] + MAX_SHOT);
		cout << ans << endl;
	}
}
