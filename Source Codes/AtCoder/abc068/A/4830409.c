#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    printf("ABC%d\n",n);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^