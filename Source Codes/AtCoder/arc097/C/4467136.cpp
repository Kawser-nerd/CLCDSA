#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
typedef pair <char, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <P> vec(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> vec[i].first >> vec[i].second;
        vec[i].second--;
    }

    int white[n][n+1]; // ?i?????i+1?????j???????????
    int black[n][n+1]; // ?i?????i+1?????j???????????

    vector <int> white_count(n, 0);
    vector <int> black_count(n, 0);

    for (int i = 0; i < 2 * n; i++) {
        char color = vec[i].first;
        int idx = vec[i].second;

        // ???
        vector <int> white_sum(n + 1, 0); // j???????????
        vector <int> black_sum(n + 1, 0); // j???????????
        for (int j = n-1; j >= 0; j--) {
            white_sum[j] = white_count[j] + white_sum[j+1];
            black_sum[j] = black_count[j] + black_sum[j+1];
        }

        for (int j = 0; j <= n; j++) {
            if (color == 'W') white[idx][j] = black_sum[j] + white_sum[idx+1];
            if (color == 'B') black[idx][j] = white_sum[j] + black_sum[idx+1];
        }

        if (color == 'W') white_count[idx]++;
        if (color == 'B') black_count[idx]++;
    }

    int dp[n+1][n+1]; // ??i????j?????????????
    fill(dp[0], dp[n+1], (1<<30));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i < n) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + white[i][j]);
            if (j < n) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + black[j][i]);
        }
    }

    cout << dp[n][n] << "\n";
    return 0;
}