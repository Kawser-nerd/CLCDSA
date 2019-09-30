#include <iostream>
#include <string>
using namespace std;

const int mod = 1000000007;

int main() {
    string s;
    cin >> s;
    long long dp[100001][4] = {};
    dp[0][0] = 1;

    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < 4; j++) {
            dp[i + 1][j] = dp[i][j] * (s[i] == '?' ? 3 : 1);
            if (j >= 1 && (s[i] == '?' || s[i] == "ABC"[j - 1])) {
                dp[i + 1][j] += dp[i][j - 1];
            }
            dp[i + 1][j] %= mod;
        }
    }

    cout << dp[s.length()][3] << endl;
}