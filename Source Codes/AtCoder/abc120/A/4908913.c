#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
int A, B, C;
scanf("%d %d %d", &A, &B, &C);

printf("%d", B/A<=C?B/A:C);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %d %d", &A, &B, &C);
 ^