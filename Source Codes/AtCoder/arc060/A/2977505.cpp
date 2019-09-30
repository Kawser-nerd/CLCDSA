#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <functional>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
#define LOG(x) cout << #x << " := " << (x) << endl
#define _LOG(x) cout << "Momentai " << x << endl
typedef long long ll;
typedef long double Lf;

const int max_N = 55;

int N, A, ar[max_N];
ll memo[max_N][max_N][max_N * max_N];

ll rec(int n, int k, int sum) {
    if (k == 0 && sum == 0) return 1;
    if (n == N || sum < 0) return 0;
    ll &ans = memo[n][k][sum];
    if (ans != -1) return ans;

    ans = rec(n+1, k, sum) + rec(n+1, k-1, sum-ar[n]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));
    cin >> N >> A;
    for (int i = 0; i < N; ++i) cin >> ar[i];
    
    ll ans = 0;
    for (int i = 1; i <= N; ++i) ans += rec(0, i, i*A);

    cout << ans << endl;

    return 0;
}