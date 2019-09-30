#include <iostream>
using namespace std;

long long MOD = 1000000007LL;
int drs[] = {1, 0, -1, 0};
int dcs[] = {0, 1, 0, -1};
int w, h;
long long grid[1050][1050];
long long dp[1050][1050];

long long dfs(int r, int c) {
    if (dp[r][c] != -1) {
        return dp[r][c];
    }
    long long res = 1;
    for (int i = 0; i < 4; ++i) {
        int nr = r + drs[i];
        int nc = c + dcs[i];
        if ((0 <= nr) && (nr < h) && (0 <= nc) && (nc < w) && (grid[nr][nc] > grid[r][c])) {
            res = (res + dfs(nr, nc)) % MOD;
        }
    }
    dp[r][c] = res;
    return res;
}

int main() {
    cin >> h >> w;
    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c) {
            cin >> grid[r][c];
            dp[r][c] = -1;
        }
    }
    long long res = 0;
    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c) {
            res = (res + dfs(r, c)) % MOD;
        }
    }
    cout << res << endl;
}