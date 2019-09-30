#include <stdio.h>
#define abs(x) (x>0) ? (x) : (-(x))
#define min(a,b) (a>b) ? (b) : (a)
int main()
{
    int i,n,h[100010],dp[100010];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",(h+i));
        if(i==0)dp[i]=0;
        else if(i==1)dp[i]=abs(h[i]-h[0]);
        else dp[i]=min((dp[i-2]+(abs(h[i]-h[i-2]))),(dp[i-1]+(abs(h[i]-h[i-1]))));
    }
    printf("%d",dp[n-1]);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",(h+i));
         ^