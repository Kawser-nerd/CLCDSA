#include <stdio.h>
int main(void)
{
    int n, k, x, y, ans=0, i;

    scanf("%d%d%d%d", &n, &k, &x, &y);
    for(i=1;i<=n;i++){
        if(i<=k)
            ans=ans+x;
        else
            ans=ans+y;
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d", &n, &k, &x, &y);
     ^