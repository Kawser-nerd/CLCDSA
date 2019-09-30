#include <stdio.h>

int main(void) {
   int siz,i;
   int total = 0;
   scanf("%d",&siz);
   int a[siz];
   for (i = 0; i < siz; i++) {
        scanf("%d",&a[i]);
        total += a[i];
   }
   if (total % 10 != 0) { printf("%d",total);  return 0 ;}
   else {
      int min= 100;
      for (i = 0; i< siz; i++ ) {
       if (a[i] % 10 != 0 &&  a[i] < min) min = a[i];
      } 
      if (min == 100) {
        printf("0");
        return 0;
      } else  { 
          printf("%d", total-min);
          return 0;
        }
   }
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&siz);
    ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^