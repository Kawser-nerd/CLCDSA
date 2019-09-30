#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    n--,m--;
    printf("%d",n*m);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^