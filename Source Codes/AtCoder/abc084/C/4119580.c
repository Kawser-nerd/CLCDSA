#include<stdio.h>
int main(void)
{
    int n,j;
    while(scanf("%d",&n)!=EOF)
    {

        int c[600],s[600],f[600];
        int i;
        for(i=1; i<n; i++)
        {
            scanf("%d%d%d",&c[i],&s[i],&f[i]);
        }
        int t=0;
        for(i=1; i<n; i++)
        {
            t=0;
            int t=0;
            t=t+c[i]+s[i];
            for(j=i; j<n-1; j++)
            {
                for(;; t++)
                {
                    if(s[j+1]<=t&&t%f[j+1]==0)
                    {
                        t+=c[j+1];
                        break;
                    }
                }
            }
            printf("%d\n",t);
        }
        printf("0\n");
    }
} ./Main.c: In function ‘main’:
./Main.c:12:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d%d%d",&c[i],&s[i],&f[i]);
             ^