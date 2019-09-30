#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool dp[5001][5001];
long N, K;
long a[5000];
bool judge(int c){
    if(a[c] >= K) return false;
    for(int i = 0; i <= N; i++){
        memset(dp[i], false, K+1);
        dp[i][0] = true;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= K; j++){
            dp[i+1][j] = dp[i][j];
        }
        if(i != c){
            for(int j = 0; j <= K; j++){
                if(dp[i][j]){
                    if(j+a[i] < K-a[c]) dp[i+1][j+a[i]] = true;
                    else if(j+a[i] < K) return false;
                }
            }
        }
    }
    return true;
}

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a+N);
    int l = 0, r = N-1;
    if(!judge(l)){
        cout << 0 << endl;
        return 0;
    }
    if(judge(r)){
        cout << N << endl;
        return 0;
    }
    int c;
    while(r-l > 1){
        c = (r+l)/2;
        if(judge(c)) l = c;
        else r = c;
    }
    cout << l+1 << endl;
}