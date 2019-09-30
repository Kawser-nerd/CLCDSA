#define P(x) cout << #x" = " << x << endl
#define PP(x, y) cout << "("#x", "#y") = (" << x << ", " << y << ")" << endl
#define PPP(x, y, z) cout << "("#x", "#y", "#z") = (" << x << ", " << y << ", " << z << ")" << endl

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
int dp[100000];
int a[100000];
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp[0] = 0;
    dp[1] = abs(a[1] - a[0]);
    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << dp[n - 1] << endl;
}