#include<stdio.h>
int main(void){
    int A,B,X;
    scanf("%d %d %d",&A,&B,&X);
    if((A+B) <X || A>X)printf("NO\n");
    else printf("YES\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&A,&B,&X);
     ^