#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int64_t N,x;
    cin>>N>>x;
    int64_t dp[N][N];//????????, ????????????
    vector<int64_t> A(N);
    for(auto &a:A) cin>>a;
    int64_t ans=0;
    for(int i=0;i<N;i++){
        dp[0][i]=A[i];
        ans+=A[i];
    }
    for(int m=1;m<N;m++){
        int64_t sum=x*m;
        dp[m][0]=min(A[0],dp[m-1][N-1]);
        sum+=dp[m][0];
        for(int i=1;i<N;i++){
            dp[m][i]=min(A[i],dp[m-1][i-1]);
            sum+=dp[m][i];
        }
        ans=min(ans,sum);
    }
    cout<<ans<<endl;

    return 0;
}