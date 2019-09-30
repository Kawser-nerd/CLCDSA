#include<stdio.h>
int main(){
    char x;
    scanf("%c",&x);
    printf("%d\n",x-'A'+1);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&x);
     ^