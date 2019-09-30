#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(void){
   int A,B,C,D,ans;
   scanf("%d%d%d%d", &A,&B,&C,&D);
   if(D <= A) ans = 0;
   if(C <= A && A<=D) ans = D - A;
   if(A <= C && D <= B) ans = D -C;
   if(C <= B && B <= D) ans = B -C;
   if(B <= C) ans = 0;
   if(C <= A && B <= D) ans = B -A;
   printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:7:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d%d%d", &A,&B,&C,&D);
    ^