#include <stdio.h>
#include <stdlib.h>
    
   int main(void){
       char x,y;
       scanf("%c %c",&x,&y);
       if(x>y){
           printf(">");
       }if(x<y){
           printf("<");
       }if(x==y){
           printf("=");
       }
   } ./Main.c: In function ‘main’:
./Main.c:6:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%c %c",&x,&y);
        ^