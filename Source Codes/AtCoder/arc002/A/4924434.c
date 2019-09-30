#include <stdio.h>
int main(void){
    int num;
    int result=0;
    scanf("%d", &num);
    
    if(num%4==0)result=1;
    if(num%100==0)result=0;
    if(num%400==0)result=1;
    
    if(result==1)printf("YES\n");
    else printf("NO\n");
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &num);
     ^