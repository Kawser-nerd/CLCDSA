#include<stdio.h>
int main()
{
    long long int s,c;
    while(scanf("%lld %lld",&s,&c)!=EOF)
    {
        long long int max;
        if(c<=2*s)
            max=c/2;
        else
            max=(2*s+c)/4;
        printf("%lld\n",max);
    }
    return 0;
}