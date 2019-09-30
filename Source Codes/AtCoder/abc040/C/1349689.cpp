#include <iostream>

using namespace std;

#define MAX_N 100001
#define INF 1 << 29

int N;
int a[MAX_N];
int dp[MAX_N];

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    fill(dp, dp + MAX_N, INF);
    dp[0] = 0;

    for (int i = 0; i < N - 1; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(a[i] - a[i + 1]));
        dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i] - a[i + 2]));
    }

    cout << dp[N - 1] << endl;
}