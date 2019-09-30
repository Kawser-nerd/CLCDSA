//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 5e3 + 10;
const long long max_val = 1LL << 62;

long long dp[maxn][maxn * 2], dp_min[maxn * 2];
int p[maxn];

long long cost(int p1, int p2, int A, int B) {
    if (p1 == p2) return 0;
    else if (p1 > p2) return B;
    else return A;
}

int main()
{
    int N, A, B, x;
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++) {
        cin >> x;
        p[x] = 2 * i - 1;
    }
    for (int i = 1; i <= N; i++) for (int j = 0; j <= 2 * N; j++) dp[i][j] = max_val;
    //dp[i][j] = min{dp[i - 1][k] + (p[i] != k) * (A | B)}
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 2 * N; j++) {
            int tail = (j % 2 == 0 ? j : j - 1);
            dp[i][j] = dp_min[tail] + cost(p[i], j, A, B);
//            for (int k = 0; k < tail; k++) {
//                //cout << j << ' ' << k << ' ' << dp[i - 1][k] << ' ' << cost(p[i], k, A, B) << endl;
//                dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost(p[i], j, A, B));
//            }
            //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
        dp_min[0] = dp[i][0];
        for (int j = 1; j <= 2 * N; j++) dp_min[j] = min(dp_min[j - 1], dp[i][j]);
    }
//    long long res = max_val;
//    for (int j = 0; j <= 2 * N; j++) res = min(res, dp[N][j]);
//    cout << res << endl;
    cout << dp_min[2 * N] << endl;
    return 0;
}