#include <stdio.h>

int main(void)
{
    int a,b,c,ans;
    scanf("%d%d%d", &a,&b,&c);

    if(a==b&&b==c) ans=1;
    else if(a!=b&&b!=c&&c!=a) ans=3;
    else ans=2;

    printf("%d", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &a,&b,&c);
     ^