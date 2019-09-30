#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define rep(i, a, N) for(int i = a; i < N; i++)

int N;
int dp[100010];

int dfs(int n) {
    if (dp[n] != -1) return dp[n];
    if (n == 0) return 0;

    int ret = n;

    for (int i = 1; i <= n; i *= 6)
        ret = min(ret, dfs(n - i) + 1);
 
     for (int i = 1; i <= n; i *= 9)
        ret = min(ret, dfs(n - i) + 1);

    return dp[n] = ret;
}

int main() {
    cin >> N;

    rep(i, 0, 100010) dp[i] = -1;
    cout << dfs(N) << endl;
}