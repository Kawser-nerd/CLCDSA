#include <iostream>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int len[10] = {0,2,5,5,4,5,6,3,7,6};
    int len_max[10] = {0};
    int prev[10001] = {0};
    int dp[100001];
    for(int i = 0; i < M; i++){
        int A;
        cin >> A;
        len_max[len[A]] = max(len_max[len[A]], A);
    }
    for(int i = 0; i <= N; i++){
        dp[i] = -1;
    }
    dp[0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j < 10; j++){
            if(i-j >= 0 && dp[i-j] >= 0 && len_max[j] != 0){
                if(dp[i] <= dp[i-j]+1){
                    if(dp[i] == dp[i-j]+1) prev[i] = max(prev[i], len_max[j]);
                    else prev[i] = len_max[j];
                    dp[i] = dp[i-j]+1;
                }
            }
        }
    }
    
    int idx = N;
    
    while(true){
        cout << prev[idx];
        idx -= len[prev[idx]];
        if(idx == 0) break;
    }
    
    cout << endl;
}