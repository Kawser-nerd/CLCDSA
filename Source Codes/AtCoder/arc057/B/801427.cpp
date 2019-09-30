#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;

constexpr LL INF = 1234567891234LL;

int N, K;
LL a[2016];
LL sa[2016];
LL dp[2016][2016];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;


    for (int j = 0; j < N; ++j) {
        cin >> a[j+1];
    }

    for (int j = 0; j < N; ++j) {
        sa[j+1] = a[j+1] + sa[j];
    }

    if (sa[N] == K) {
        cout << 1 << endl;
        return 0;
    }

    for (int j = 0; j <= N; ++j) {
        fill(dp[j], dp[j] + N + 1, INF);
    }

    sa[0] = 1;
    dp[0][0] = 0;

    for (int j = 1; j <= N; ++j) {
        for (int k = 0; k <= N; ++k) {
            dp[j][k] = dp[j-1][k];

            if (k > 0 && dp[j-1][k-1] < INF) {
                LL w = dp[j-1][k-1] * a[j] / sa[j-1] + 1;

                dp[j][k] = min(dp[j][k], dp[j-1][k-1] + w);
            }
        }
    }

    for (int j = N; j >= 0; --j) {
        if (dp[N][j] <= K) {
            cout << j << endl;
            break;
        }
    }

    return 0;
}