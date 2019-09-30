/**
 * C - Strange Bank
 */

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1 << 29;
int dp[13][100001];

int main() {

    int N;
    vector<int> v;

    //
    cin >> N;
    v.push_back(1);
    for (int i = 6; i <= N; i *= 6) { v.push_back(i); }
    for (int i = 9; i <= N; i *= 9) { v.push_back(i); }
    sort(v.begin(), v.end());

    //
    fill(dp[0], dp[13], INF);
    dp[0][0] = 0;

    for (int i = 1; i <= v.size(); i++) {
        for (int j = 0; j <= N; j++) {
            if (j < v[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - v[i - 1]] + 1);

            }
        }
    }
    cout << dp[v.size()][N] << endl;
} ./Main.cpp:26:17: warning: array index 13 is past the end of the array (which contains 13 elements) [-Warray-bounds]
    fill(dp[0], dp[13], INF);
                ^  ~~
./Main.cpp:11:1: note: array 'dp' declared here
int dp[13][100001];
^
1 warning generated.