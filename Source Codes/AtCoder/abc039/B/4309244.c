#include<stdio.h>
#include<math.h>
int main(n){
  scanf("%d",&n);
  printf("%d",(int)sqrt(sqrt(n)));
} ./Main.c: In function ‘main’:
./Main.c:3:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
 int main(n){
     ^
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^