#include<stdio.h>
#define m 200000
int main()
{
    int a[m],i,n,sum1=0,sum2=0,sum3=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%4==0)
            sum1++;
        if(a[i]%2==0)
            sum2++;
    }
    sum3=n-sum2;
    if(n<=3&&sum1>=1)printf("Yes");
    else if(sum2==n||((sum1>=sum3-1)&&sum2-sum1==0))printf("Yes");
    else if(sum2==n||sum1>=sum3)printf("Yes");
    else printf("No");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^