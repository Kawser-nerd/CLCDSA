#include<stdio.h>

 int main(){
   int y, m, d;

   scanf("%d/%d/%d", &y, &m, &d);
   if(y < 2019){
     printf("Heisei\n");
   }
   else if(y == 2019 && m <= 4){
     printf("Heisei\n");
   }
   else{
     printf("TBD\n");
   }
   return 0;
 } ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d/%d/%d", &y, &m, &d);
    ^