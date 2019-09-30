#include <cstdio>

int main(void)
{
    int A,B,N;
    scanf("%d%d%d",&N,&A,&B);
    if(N==1)
    {
        if(A==B)
            printf("1\n");
        else
            printf("0\n");
    }
    else 
    {
        if(A>B)
            printf("0\n");
        else
            printf("%lld\n",(long long )(B-A)*(N-2)+1);
    }
    return 0;
}