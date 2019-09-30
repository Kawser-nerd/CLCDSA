#include<stdio.h>
#include<string.h>
int main(void){
    int n;
    scanf("%d",&n);
    n=1000-n+110;

    printf("%d",n);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^