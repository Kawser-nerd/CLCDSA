#include<stdio.h>
int main(void){
    int X,A,B;
    scanf("%d",&X);
    scanf("%d",&A);
    scanf("%d",&B);
    int money = X - A; //???????
    money = money - B * (money / B);
    printf("%d\n",money);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&X);
     ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&B);
     ^