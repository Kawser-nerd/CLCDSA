#include<stdio.h>

int main(){
  long A, B, C, V;
  scanf("%lld %lld %lld", &A, &B, &C);
  A = A%(1000000000 + 7);
  B = B%(1000000000 + 7);
  C = C%(1000000000 + 7);
  A = (A*B)%(1000000000 + 7);
  V = (A*C)%(1000000000 + 7);
  
  printf("%lld\n", V);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘long int *’ [-Wformat=]
   scanf("%lld %lld %lld", &A, &B, &C);
         ^
./Main.c:5:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 3 has type ‘long int *’ [-Wformat=]
./Main.c:5:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 4 has type ‘long int *’ [-Wformat=]
./Main.c:12:10: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘long int’ [-Wformat=]
   printf("%lld\n", V);
          ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld", &A, &B, &C);
   ^