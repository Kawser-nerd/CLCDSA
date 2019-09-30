#include<stdio.h>
int main()
{
    int a,b,c,n,m;
    scanf("%d %d %d",&a,&b,&c);
    n=(b-a);
    m=(c-b);
    if(n==m)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}