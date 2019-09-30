#include<stdio.h>

int main(void)
{
    int a;
    scanf("%d",&a);
    if(a%2==0){
        printf("%d",a);
    } else{
        printf("%d",a*2);
    }
    
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^