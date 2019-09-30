#include <stdio.h>

int main(void)
{
    int n,i;
    double ans=0;
    scanf("%d",&n);
    
    for(i=1;i<=n;i++){
        ans += i*10000*(1/(double)n);
    }
    printf("%d\n",(int)ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^