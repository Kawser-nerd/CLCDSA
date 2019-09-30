#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long int len;
    scanf("%lld",&len);

    long long int n,m;
    scanf("%lld %lld",&n,&m);

    if(len==1)
    {
        if(n==m)
            printf("1\n");
        else
            printf("0\n");
    }
    else
    {
        if(n>m)
            printf("0\n");
        else
        {
          long long int min=n*(len-1)+m;
          long long int max=n+(len-1)*m;
          printf("%lld\n",max-min+1);
        }

    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&len);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&n,&m);
     ^