#include <stdio.h>

int main()
{   int n;
    scanf("%d",&n);
    int ans=0;
    ans+=(n/10)*100;
    n%=10;
    if(n>6)ans+=100;
    else ans+=n*15;
    printf("%d\n",ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^