#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
int64_t dp[100000][3];
int main(){
    int N;
    cin>>N;
    cin>>dp[0][0];
    dp[0][2]=dp[0][1]=-1e16;
    for(int i=1;i<N;i++){
        int A;
        char op;
        cin>>op;
        cin>>A;
        if(op=='+'){
            dp[i][0]=max({dp[i-1][0]+A,dp[i-1][1]-A,dp[i-1][2]+A});
            dp[i][1]=max({dp[i-1][1]-A,dp[i-1][2]+A});
            dp[i][2]=dp[i-1][2]+A;
        }else{
            dp[i][0]=max({dp[i-1][0]-A,dp[i-1][1]+A,dp[i-1][2]-A});
            dp[i][1]=max({dp[i-1][0]-A,dp[i-1][1]+A,dp[i-1][2]-A});
            dp[i][2]=max(dp[i-1][1]+A,dp[i-1][2]-A);
        }
    }
    cout<<max({dp[N-1][0],dp[N-1][1],dp[N-1][2]})<<endl;
    return 0;
}