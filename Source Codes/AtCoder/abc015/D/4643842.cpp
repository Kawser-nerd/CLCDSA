#include<cstdio>
#include<algorithm>
using namespace std;
int w,n,k,dp[51][100001]={},a,b,ans=0;
int main(){
    scanf("%d",&w);
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        for(int j=k-1;j>=0;j--){
            for(int l=w-a;l>=0;l--){
                dp[j+1][l+a]=max(dp[j+1][l+a],dp[j][l]+b);
            }
        }
    }
    for(int i=0;i<=k;i++){
        for(int j=0;j<=w;j++){
            ans=max(ans,dp[i][j]);
        }
    }
    printf("%d\n",ans);
}