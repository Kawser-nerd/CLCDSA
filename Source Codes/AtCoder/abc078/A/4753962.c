#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(void) {
   char X, Y;
   scanf("%c %c", &X, &Y);
   if (X < Y) {
      printf("<\n");
   } else if (X > Y) {
      printf(">\n");
   } else {
      printf("=\n");
   }
   return 0;


} ./Main.c: In function ‘main’:
./Main.c:7:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%c %c", &X, &Y);
    ^