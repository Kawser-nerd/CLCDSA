#include<stdio.h>
int main(void){
    int n,cnt = 0;
    scanf("%d",&n);
    cnt = n%2 == 0 ? n/2 : n/2+1;
    printf("%d\n",cnt);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^