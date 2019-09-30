#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  long long int n, m;
  scanf("%lld %lld",&n,&m);
  if(n==1 && m==1) printf("1\n");
  else if(n==1 || m==1) printf("%lld\n",n*m-2);
  else printf("%lld\n",(n-2)*(m-2));

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&n,&m);
   ^