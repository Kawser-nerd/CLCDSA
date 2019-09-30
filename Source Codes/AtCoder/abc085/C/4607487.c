#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(void){
   int N;
   int Y;
   scanf("%d%d", &N,&Y);
   int x,y,z;
   for (x = 0; x < N+1; x++) {
      for ( y = 0; y < 9; y++) {
         z = N - x - y;
         if (z < 0) {
            break;
         }else{
            if (x*10000 + y*5000 + z*1000==Y) {
               printf("%d %d %d\n",x,y,z);
               return 0;
            }
         }
      }
   }
   printf("-1 -1 -1\n");
   return 0;

} ./Main.c: In function ‘main’:
./Main.c:8:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d", &N,&Y);
    ^