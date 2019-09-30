#include<stdio.h>
int main(void)
{
    int a,b,n;
    scanf("%d \n",&a);
    scanf("%d \n",&b);
    scanf("%d \n",&n);
    LABEL1:
    if(n%a==0 && n%b==0){
        printf("%d\n",n);
        return 0;
    }
    n=n+1;
    goto LABEL1;
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d \n",&a);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d \n",&b);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d \n",&n);
     ^