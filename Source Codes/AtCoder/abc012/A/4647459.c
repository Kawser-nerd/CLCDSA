#include<stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int tmp = a;
    a = b;
    b = tmp;
    printf("%d %d\n",a,b);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^