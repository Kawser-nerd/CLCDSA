#include<cstdio>
#define mod 1000000007
using namespace std;
int main(){
    int dp[100001],sum[100002]={},n,m,f,x[100001],l;
    scanf("%d %d",&n,&m);
    dp[0]=1;
    sum[0]=0;
    sum[1]=1;
    l=0;
    for(int i=1;i<=m;i++){
        x[i]=-1;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&f);
        if(x[f]>l){
            l=x[f];
        }
        x[f]=i+1;
        dp[i+1]=sum[i+1]-sum[l];
        if(dp[i+1]<0){
            dp[i+1]+=mod;
        }
        dp[i+1]%=mod;
        sum[i+2]=sum[i+1]+dp[i+1];
        sum[i+2]%=mod;
    }
    printf("%d\n",dp[n]);
}