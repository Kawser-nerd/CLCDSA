#include <stdio.h>

int main(){
    int Y;
    scanf("%d", &Y);

    if(Y%400==0 || (Y%100!=0 && Y%4==0)){
        printf("YES\n");
    }else{
        printf("NO\n");
    }   

return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &Y);
     ^