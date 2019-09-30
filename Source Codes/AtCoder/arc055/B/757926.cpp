#include <iostream>
#include <cstdio>
#include <cassert>

#define MAX_N 1000
#define MAX_K 1000

using namespace std;

int n, k;
double dp[MAX_N + 1][MAX_K + 1];

double f(int i, int l)
{
    assert(i <= n && l <= k);
    if (dp[i][l] >= -0.1) {
        return dp[i][l];
    }
    if (l == 0) {
        return dp[i][l] = 0.0;
    }
    if (n - i + 1 <= l) {
        return dp[i][l] = 1.0;
    }
    double p = (double) n / (i * (n - i + 1));
    double q = (double) i / n;
    return dp[i][l] = (1.0 - p) * f(i + 1, l) + p * max(q + (1.0 - q) * f(i + 1, l - 1), (1.0 - q) * f(i + 1, l));
}

using namespace std;

int main(void)
{
    cin >> n;
    cin >> k;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = -1.0;
        }
    }
    cout << f(1, k) << endl;
    return 0;
}