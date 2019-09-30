#include <iostream>
using namespace std;

const int MAX_N = 110000;

int dp[MAX_N]; 

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < MAX_N; ++i) dp[i] = N; 
    dp[0] = 0;

    for (int n = 1; n <= N; ++n) {
        for (int pow6 = 1; pow6 <= n; pow6 *= 6) {
            dp[n] = min(dp[n], dp[n - pow6] + 1);
        }
        for (int pow9 = 1; pow9 <= n; pow9 *= 9) {
            dp[n] = min(dp[n], dp[n - pow9] + 1);
        }
    }

    cout << dp[N] << endl;
}