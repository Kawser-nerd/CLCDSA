#include<stdio.h>

int main(void){
    int a,b,c;
    scanf("%d %d %d\n",&a,&b,&c);
    if(a*b%2==0){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d\n",&a,&b,&c);
     ^