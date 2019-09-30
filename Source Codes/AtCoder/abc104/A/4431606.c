#include<stdio.h>

int main(void){
    int r;
    scanf("%d\n",&r);
    if (r<1200){
        printf("ABC\n");
    }
    else{
        if(r<2800){
            printf("ARC\n");
        }
        else{
            printf("AGC\n");
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n",&r);
     ^