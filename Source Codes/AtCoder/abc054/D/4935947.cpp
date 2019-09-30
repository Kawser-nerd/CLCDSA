#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int N, ma, mb, MAX_A=0, MAX_B=0;
    cin >> N >> ma >> mb;
    vector<int> a(N), b(N), c(N);
    for(int i=0; i<N; i++){
        cin >> a[i] >> b[i] >> c[i];
        MAX_A=max(MAX_A, a[i]);
        MAX_B=max(MAX_B, b[i]);
    }
    
    int dp[N+1][MAX_A*N+1][MAX_B*N+1];
    int inf=1000000000;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=MAX_A*N; j++){
            for(int k=0; k<=MAX_B*N; k++){
                dp[i][j][k]=inf;
            }
        }
    }
    dp[0][0][0]=0;

    for(int i=0; i<N; i++){
        for(int ac=0; ac<=MAX_A*N; ac++){
            for(int bc=0; bc<=MAX_B*N; bc++){
                if(dp[i][ac][bc]!=inf){
                    dp[i+1][ac][bc]=min(dp[i][ac][bc], dp[i+1][ac][bc]);
                    dp[i+1][ac+a[i]][bc+b[i]]=min(dp[i][ac][bc]+c[i], dp[i+1][ac+a[i]][bc+b[i]]);
                }
            }
        }
    }
    int counter=1, ans=inf;
    while(ma*counter<=MAX_A*N && mb*counter<=MAX_B*N){
        ans=min(ans, dp[N][ma*counter][mb*counter]);
        counter++;
    }
    if(ans==inf){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }


    return 0;
}