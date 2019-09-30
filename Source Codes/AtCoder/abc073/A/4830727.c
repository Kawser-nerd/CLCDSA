#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    if(a/90==1||a%10==9)printf("Yes\n");
    else printf("No\n");
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^