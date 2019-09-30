#include<stdio.h>
int main(){
    int x,ans = 0;
    scanf("%d",&x);
    ans = x/10 + x%10;
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^