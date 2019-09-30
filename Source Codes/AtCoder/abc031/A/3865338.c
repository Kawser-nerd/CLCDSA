#include<stdio.h>
int main(void)
{
    int A,D,x1,x2;
    scanf("%d",&A);
    scanf("%d",&D);
    x1=(A+1)*D;
    x2=A*(D+1);
    if(x1>=x2){
        printf("%d\n",x1);
    }
    if(x2>x1){
        printf("%d\n",x2);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&D);
     ^