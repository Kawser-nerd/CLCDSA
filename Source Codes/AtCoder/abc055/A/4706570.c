#include<stdio.h>
int main(){
    int a,c = 0;
    scanf("%d",&a);
    c = a/15;
    a *= 800;
    printf("%d\n",a-200*c);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^