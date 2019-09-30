#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
const int BUF = 2005;

int N, K;
int nMatch[BUF];

void read() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> nMatch[i];
    }
}


void work() {
    // sum[idx]: nMatch[0] + nMatch[1] + ... + nMatch[idx]
    int sum[BUF];
    sum[0] = nMatch[0];
    for (int i = 1; i < N; ++i) {
        sum[i] = sum[i - 1] + nMatch[i];
    }
    
    // lowbound[idx]: K - nMatch[N - 1] - nMatch[N - 2] ... nMatch[idx]
    int lowbound[BUF];
    lowbound[N] = K;
    for (int i = N - 1; i >= 0; --i) {
        lowbound[i] = lowbound[i + 1] - nMatch[i];
    }
    
    // dp[???][?????????] := ?????????
    static int dp[BUF][BUF];
    for (int i = 0; i < BUF; ++i)
        for (int j = 0; j < BUF; ++j)
            dp[i][j] = INT_MAX;

    dp[0][0] = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= i; ++j) {
            if (dp[i][j] == INT_MAX) {
                continue;
            }

            // ????????????
            {
                long long needWins;
                if (i == 0) {
                    needWins = 1;
                }
                else {
                    // i - 1 ??????
                    needWins = (1LL * nMatch[i] * dp[i][j]) / sum[i - 1] + 1;
                }
                
                needWins = max(needWins, (long long) (lowbound[i + 1] - dp[i][j]));
                
                if (needWins <= nMatch[i] && dp[i][j] + needWins <= K) {
                    dp[i + 1][j + 1] = min((long long) dp[i + 1][j + 1], dp[i][j] + needWins);
                }
            }
            
            // ?????
            if (max(lowbound[i + 1], dp[i][j]) - dp[i][j] <= nMatch[i]) {
                dp[i + 1][j] = min(dp[i + 1][j], max(lowbound[i + 1], dp[i][j]));
            }
        }

    for (int i = N; i >= 0; --i)
        if (dp[N][i] != INT_MAX) {
            cout << i << endl;
            break;
        }
}


int main() {
    read();
    work();
    return 0;
}