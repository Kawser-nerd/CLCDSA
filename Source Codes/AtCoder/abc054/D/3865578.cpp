#include <iostream>
using namespace std;

const int maxN = 40, maxA = 10, maxB = 10, inf = 1000000;

int main(void){
    // Your code here!
    int N, Ma, Mb;
    int ans;
    cin >> N >> Ma >> Mb;
    
    int dp[N+1][maxA*maxN+1][maxB*maxN+1];
    int i, j, k;
    
    for(i=0; i<=N; i++){
        for(j=0; j<=maxA*maxN; j++){
            for(k=0; k<= maxB*maxN; k++){
                dp[i][j][k] = inf;
            }
        }
    }
    
    dp[0][0][0] = 0;
    int a, b, c;
    
    for(i=0; i<N; i++){
        cin >> a >> b >> c;
        for(j=0; j<=maxA*maxN; j++){
            for(k=0; k<= maxB*maxN; k++){
                if(j-a < 0 || k-b < 0){
                    dp[i+1][j][k] = dp[i][j][k];
                }
                else {
                    dp[i+1][j][k] = min(dp[i][j][k], dp[i][j-a][k-b]+c);
                }
            }
        }
    }
    
    ans = inf;
    a = Ma;
    b = Mb;
    while(a <= maxA*maxN && b <= maxB*maxN){
        ans = min(ans, dp[N][a][b]);
        a = a+Ma;
        b = b+Mb;
    }
    
    if (ans==inf){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }

}