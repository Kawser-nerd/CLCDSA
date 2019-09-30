#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

ll n, a[2];
ll S[100010];
std::vector<ll> A[2];
ll dp[100010][2];

int main() {
    std::cin >> n >> a[0] >> a[1];
    
    for(int i = 0; i < n; ++i) {
        std::cin >> S[i];
        
        if(i != 0) {
            if(S[i] - S[i - 1] < a[0]) {
                A[0].push_back(i - 1);
            }
            if(S[i] - S[i - 1] < a[1]) {
                A[1].push_back(i - 1);
            }
        }
    }
    
    dp[0][0] = dp[0][1] = 1;
    
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < 2; ++j) {
            int l = std::upper_bound(S, S + i, S[i] - a[j]) - S - 1;
            
            if(l == -1) {
                if(std::lower_bound(A[!j].begin(), A[!j].end(), i - 1) == A[!j].begin()) {
                    dp[i][j] += 1;
                }
            }else {
                if(l == i - 1) {
                    dp[i][j] += dp[l][!j] + dp[l][j];
                }else {
                    if(std:: lower_bound(A[!j].begin(), A[!j].end(), i - 1) <= std::lower_bound(A[!j].begin(), A[!j].end(), l + 1)) {
                        dp[i][j] += dp[l + 1][!j];
                    }
                }
            }
            dp[i][j] %= ll(1e9 + 7);
        }
    }
    std::cout << (dp[n - 1][0] + dp[n - 1][1]) % ll(1e9+7) << std::endl;
}