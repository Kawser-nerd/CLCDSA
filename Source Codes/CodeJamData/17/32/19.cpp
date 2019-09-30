#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const int INF = 1e9;

const int MAX_TIME = 1440;

int tp[MAX_TIME];

int dp[MAX_TIME + 1][MAX_TIME + 1][2];

void Solve() {
    int result = INF;
    for (int startTp = 0; startTp < 2; ++startTp) {
        for (int i = 0; i <= MAX_TIME; ++i) {
            for (int j = 0; j <= MAX_TIME; ++j) {
                for (int t = 0; t < 2; ++t) {
                    dp[i][j][t] = INF;
                }
            }
        }
        dp[0][0][startTp] = 0;
        for (int pos = 0; pos < MAX_TIME; ++pos) {
            for (int s0 = 0; s0 <= MAX_TIME; ++s0) {
                for (int ctp = 0; ctp < 2; ++ctp) {
                    if (dp[pos][s0][ctp] == INF) {
                        continue;
                    }

                    for (int ntp = 0; ntp < 2; ++ntp) {
                        if (tp[pos] != ntp) {
                            const int ns0 = s0 + (ntp == 0);
                            dp[pos + 1][ns0][ntp] = min(dp[pos + 1][ns0][ntp],
                                    dp[pos][s0][ctp] + (ntp != ctp));
                        }
                    }
                }
            }
        }
        const int curResult = min(dp[MAX_TIME][MAX_TIME / 2][startTp],
            dp[MAX_TIME][MAX_TIME / 2][1 - startTp] + 1);
        result = min(result, curResult);
    }
    cout << result << endl;
}

void Read() {
    int n1, n2;
    cin >> n1 >> n2;
    for (int i = 0; i < MAX_TIME; ++i) {
        tp[i] = -1;
    }
    for (int i = 0; i < n1 + n2; ++i) {
        const int ctp = (i < n1 ? 0 : 1);
        int l, r;
        cin >> l >> r;
        for (int j = l; j < r; ++j) {
            tp[j] = ctp;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        Read();
        cout << "Case #" << test << ": ";
        Solve();
    }

    return 0;
}
