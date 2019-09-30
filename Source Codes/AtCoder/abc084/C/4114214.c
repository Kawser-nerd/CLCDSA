#include<stdio.h>
int main()
{
    int n,c[510],s[510],f[510],i,j,k,sum=0;
    scanf("%d",&n);
    for(i=1;i<n;i++)
        scanf("%d%d%d",&c[i],&s[i],&f[i]);
    for(i=1;i<=n-1;i++)
    {
        sum=s[i]+c[i];
        for(j=1;j<n-i;j++)
        {
            int m;
            if(sum<s[i+j])
                m=s[i+j];
            else
            {
                for(k=1;;k++)
                {
                    m=s[i+j]+k*f[i+j];
                    if(m>=sum && m%f[i+j]==0)break;
                }
            }
            sum=m+c[i+j];
        }
        printf("%d\n",sum);
    }
    if(i==n)printf("0\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&c[i],&s[i],&f[i]);
         ^