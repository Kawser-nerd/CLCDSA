#include <stdio.h>
#include <math.h>
int main(void)
{
 int A, B, X, i, j;
 scanf("%d %d", &A, &B);
 if(B < 10) {
   X = A * 10 + B;
 }
 else if(B < 100) {
   X = A * 100 + B;
 }
 else{
   X = A * 1000 + B;
 }
 for(j = 3; j * j <= 100100; j++) {
   if(X == j * j) {
     printf("Yes");
     return 0;
   }
 }
   printf("No");
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &A, &B);
  ^