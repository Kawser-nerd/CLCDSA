#include<stdio.h>
#include<math.h>
int main()
{
    int num,i,j;
    scanf("%d",&num);
    long long s[num],sum=0,min,d[num-1],t;
    for(i=0,j=0;i<num;i++,j++)
        {
            scanf("%lld",&s[i]);
            sum=sum+s[i];
            if(j<num-1)
                d[j]=sum;
        }
    min=fabs(sum-2*d[0]);
    for(i=1;i<num-1;i++)
    {
        t=fabs(sum-2*d[i]);
        if(min>t)
            min=t;
    }
        printf("%lld",min);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&num);
     ^
./Main.c:10:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%lld",&s[i]);
             ^