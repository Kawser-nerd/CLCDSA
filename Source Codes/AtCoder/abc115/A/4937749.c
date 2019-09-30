#include<stdio.h>
int main(void)
{
    int a, b, i;
    
    scanf("%d", &a);
    
    b = 25 - a;

    if(b == 0){
        printf("Christmas\n");
    }else{
        printf("Christmas ");
        for(i = 0; i <= b - 1; i++){
            printf("Eve ");
        }
        printf("\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^