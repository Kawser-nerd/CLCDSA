#include<stdio.h>
int d,n;
int main(void){
    scanf("%d%d",&d,&n);
    if(d == 0){
        if(n == 100){
            printf("101");
        }else{
        printf("%d",n);
        
    }}else if(d == 1){
         if(n == 100){
            printf("10100");
        }else{
        printf("%d",n*100);
    }}else if(d == 2){
         if(n == 100){
            printf("1010000");
        }else{
        printf("%d",n*10000);
        }
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&d,&n);
     ^