#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    if(a<1200)printf("ABC\n");
    else printf("ARC\n");
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^