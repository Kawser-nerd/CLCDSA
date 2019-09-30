#include<stdio.h>
int main(void){
    int a,b;
    int sum = 0;
    scanf("%d%d",&a,&b);
    sum = b - a + 1;
    printf("%d\n",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^