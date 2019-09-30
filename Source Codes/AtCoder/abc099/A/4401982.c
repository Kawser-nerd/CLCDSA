#include<stdio.h>

int main(void)
{
    int a;//b;
    scanf("%d",&a);
    if (a>999){
        printf("ABD");
    } else {
        printf("ABC");
    }
    
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^