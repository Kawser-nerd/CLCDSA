#include <stdio.h>
#include <stdlib.h>
    
   int main(void){
       int a;
       scanf("%d",&a);
       if(a==7){
           printf("YES");
       }else if(a==5){
           printf("YES");
       }else if(a==3){
           printf("YES");
       }else{
           printf("NO");
       }
       
   } ./Main.c: In function ‘main’:
./Main.c:6:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%d",&a);
        ^