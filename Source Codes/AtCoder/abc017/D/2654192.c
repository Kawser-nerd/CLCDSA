#include <stdio.h>
    #define MOD (1e9+7);
    int main(){
        int n,m;
        scanf("%d %d",&n,&m);
     
        int f[100001]={0};
        int i,j;
        //*
        for(i=1;i<=n;i++){
            scanf("%d",&f[i]);
        }
        long long dp[100001]={0};
        dp[0]=1;
        int flag[100001]={0};
        long long sum =1;
        i=0;
        for(j=1;j<=n;j++){
            flag[f[j]]++;
            while(flag[f[j]]>2||(flag[f[j]]>1&&f[j]!=f[i])){
                sum=(sum-dp[i]+1000000007)%1000000007;
                flag[f[i]]--;
                i++;
            }
            dp[j]=sum;
            sum=(sum+dp[j])%1000000007;
        }
        printf("%lld\n",dp[n]%1000000007);
    } ./Main.c: In function ‘main’:
./Main.c:5:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&n,&m);
         ^
./Main.c:11:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&f[i]);
             ^