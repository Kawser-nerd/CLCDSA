#include <stdio.h>

int main()
{
    int k;
    scanf("%d",&k);
    int ans;
    ans = (k/2) * ((k+1)/2);
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&k);
     ^