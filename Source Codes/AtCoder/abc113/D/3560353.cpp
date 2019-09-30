// D.

#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int h, w, k;
	cin >> h >> w >> k;
	int dp[102][8] = {};
	dp[0][0] = 1;
	for (int i = 0; i < h; ++i) {
		for (int b = 0; b < (1 << (w - 1)); ++b) {
			bool skip = false;
			for (int j = 3; j <= b; j *= 2) {
				if ((b & j) == j) {
					skip = true;
				}
			}
			if (!skip) {
				int prev_dir = 0;
				for (int j = 0; j < w; ++j) {
					int dir = (b & (1 << j)) != 0;
					dp[i + 1][j + dir - prev_dir] += dp[i][j];
					dp[i + 1][j + dir - prev_dir] %= 1000000007;
					prev_dir = dir;
				}
			}
		}
	}
	int ans = dp[h][k - 1];
	cout << ans << endl;
	return 0;
}