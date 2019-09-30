#include <iostream>
#include <vector>
using namespace std;

long long MOD = 1000000007;
vector<int> C;
long long dp[200005];
long long dp2[200005];

int main(void){
    int N; cin >> N;
    for (int i = 0; i < N; i++){
        int c; cin >> c;
        C.push_back(c);
    }
    vector<int> tmp;
    for (int i = 0; i < N; i++){
        if (i == 0){
            tmp.push_back(C[i]);
        }else if (*tmp.rbegin() != C[i]){
            tmp.push_back(C[i]);
        }
        if (i == N-1) C = tmp;
    }
    dp[0] = 1;
    for (int i = 0; i < C.size(); i++){
        dp[i+1] += dp[i];
        dp[i+1] %= MOD;
        dp[i+1] += dp2[C[i]];
        dp[i+1] %= MOD;
        dp2[C[i]] += dp[i];
        dp2[C[i]] %= MOD;
    }
    cout << dp[C.size()] << endl;
    return 0;
}