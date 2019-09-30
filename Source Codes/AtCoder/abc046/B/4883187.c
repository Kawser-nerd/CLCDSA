#include <stdio.h>

int main(void)
{
    int n,k,ans;
    scanf("%d%d", &n,&k);
    ans=k;

    for(int i=0; i<n-1; i++) ans*=k-1; 
    printf("%d", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n,&k);
     ^