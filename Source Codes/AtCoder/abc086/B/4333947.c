#include <stdio.h>

int main(){
  int a,b,c;
  scanf("%d %d",&a,&b);
  if(b<10) c = 10*a + b;
  else if(b<100) c = 100*a + b;
  else c = 1000*a + b;

  int d = sqrt(c);
  if(d*d == c) printf("Yes");
  else printf("No");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:11: warning: implicit declaration of function ‘sqrt’ [-Wimplicit-function-declaration]
   int d = sqrt(c);
           ^
./Main.c:10:11: warning: incompatible implicit declaration of built-in function ‘sqrt’
./Main.c:10:11: note: include ‘<math.h>’ or provide a declaration of ‘sqrt’
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^