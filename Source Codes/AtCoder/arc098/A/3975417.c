#include <stdio.h>
#define min(a,b) (a<b?a:b)
#define inf 1<<30

int main(void){
    int n,i;
    scanf("%d\n",&n);
    char dir[n];
    int sum_W[n+1],sum_E[n+1];
    for(i=0;i<n+1;i++)
    {
        sum_W[i]=sum_E[i]=0;
    }
    
    for(i=0;i<n;i++)
    {
        scanf("%c",&dir[i]);
    }
    
    for(i=0;i<n;i++)
    {
        if(dir[i]=='W')
        {
            sum_W[i+1]=sum_W[i]+1;
            sum_E[i+1]=sum_E[i];
        }
        else
        {
            sum_W[i+1]=sum_W[i];
            sum_E[i+1]=sum_E[i]+1;
        }
    }
    
    int cost,ans=inf;
    for(i=0;i<n;i++)
    {
        cost=sum_W[i]+(sum_E[n]-sum_E[i+1]);
        ans=min(cost,ans);
    }
    
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n",&n);
     ^
./Main.c:17:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%c",&dir[i]);
         ^