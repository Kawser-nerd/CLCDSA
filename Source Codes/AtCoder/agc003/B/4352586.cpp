#include <iostream>

using namespace std;

int main(){
    int N;
    long A[100000];
    long dp[2][100000];
    long sum = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        sum += A[i];
    }
    if(A[0]%2 == 0){
        dp[1][0] = -1;
        dp[0][0] = 0;
    }else{
        dp[1][0] = 1;
        dp[0][0] = -1;
    }
    for(int i = 1; i < N; i++){
        if(A[i] == 0){
            if(dp[0][i-1] == -1 && dp[1][i-1] == -1) dp[0][i] = -1;
            if(dp[0][i-1] == -1 && dp[1][i-1] != -1) dp[0][i] = dp[1][i-1];
            if(dp[0][i-1] != -1 && dp[1][i-1] == -1) dp[0][i] = dp[0][i-1];
            if(dp[0][i-1] != -1 && dp[1][i-1] != -1) dp[0][i] = min(dp[0][i-1], dp[1][i-1]);
            dp[1][i] = -1;
        }else if(A[i]%2 == 0){
            if(dp[0][i-1] == -1 && dp[1][i-1] == -1) dp[0][i] = -1;
            if(dp[0][i-1] == -1 && dp[1][i-1] != -1) dp[0][i] = dp[1][i-1];
            if(dp[0][i-1] != -1 && dp[1][i-1] == -1) dp[0][i] = dp[0][i-1];
            if(dp[0][i-1] != -1 && dp[1][i-1] != -1) dp[0][i] = min(dp[0][i-1], dp[1][i-1]);
            dp[1][i] = dp[1][i-1];
        }else{
            if(dp[0][i-1] == -1 && dp[1][i-1] == -1) dp[1][i] = -1;
            if(dp[0][i-1] == -1 && dp[1][i-1] != -1) dp[1][i] = dp[1][i-1]+1;
            if(dp[0][i-1] != -1 && dp[1][i-1] == -1) dp[1][i] = dp[0][i-1]+1;
            if(dp[0][i-1] != -1 && dp[1][i-1] != -1) dp[1][i] = min(dp[0][i-1]+1, dp[1][i-1]+1);
            if(dp[1][i-1] == -1) dp[0][i] = -1;
            if(dp[1][i-1] != -1) dp[0][i] = dp[1][i-1]-1;
        }
    }
    /*
    for(int i = 0; i < N; i++) cout << dp[0][i] << ' ';
    cout << endl;
    for(int i = 0; i < N; i++) cout << dp[1][i] << ' ';
    cout << endl;
    */
    long rem = INT32_MAX;
    if(dp[0][N-1] != -1) rem = min(rem, dp[0][N-1]);
    if(dp[1][N-1] != -1) rem = min(rem, dp[1][N-1]);
    cout << (sum-rem)/2 << endl;
}