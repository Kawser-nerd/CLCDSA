#include <stdio.h>
int main(){
    int n,sum = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)sum += i;
    printf("%d\n",sum);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^