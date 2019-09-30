#include <stdio.h>
int main(void){
   int i;
   char C[3][3];
   for(i=0;i<3;i++){
       scanf("%s",C[i]);
       }
       for(i=0;i<3;i++)
        printf("%c",C[i][i]);
       return(0);
   } ./Main.c: In function ‘main’:
./Main.c:6:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%s",C[i]);
        ^