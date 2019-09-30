#include<stdio.h>
int main()
{
    long long int n,i,j,a,b,result,p,q,s,r[100005];
    while(scanf("%lld %lld %lld",&n,&a,&b)!=EOF)
    {
        result=0;
        for(i=0; i<n; i++)
        {
            scanf("%lld",&r[i]);
        }
        for(i=0; i<n-1; i++)
        {
            p=r[i+1]-r[i];
            q=p*a;
            if(q>=b)
            {
                result=result+b;
            }
            else
            {
                result=result+q;
            }

        }
        printf("%lld\n",result);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%lld",&r[i]);
             ^