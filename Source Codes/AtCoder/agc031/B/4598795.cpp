#include<cstdio>
#include<vector>
#define mod 1000000007
using namespace std;
int n,c[200001],dp[200001],sum[200000]={},l[200001];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    c[n]=100000000;
    dp[0]=1;
    for(int i=0;i<n;i++){
        dp[i+1]=dp[i];
        dp[i+1]%=mod;
        if(i==0||c[i-1]!=c[i]){
            l[c[i]]=i;
            dp[i+1]+=sum[c[i]];
            dp[i+1]%=mod;
        }
        if(c[i]!=c[i+1]){
            sum[c[i]]+=dp[l[c[i]]];
            sum[c[i]]%=mod;
        }
    }
    printf("%d\n",dp[n]);
}