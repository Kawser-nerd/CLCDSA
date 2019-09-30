#include <stdio.h>
#include <stdlib.h>
    
   int main(void){
       int a;
       scanf("%d",&a);
       printf("%d",a/3);
   } ./Main.c: In function ‘main’:
./Main.c:6:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%d",&a);
        ^