#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  long int n,a,b,i,cnt=0;
  scanf("%ld %ld %ld",&n,&a,&b);
  if(a>b) cnt=0;
  else if(n==1){
    if(a!=b) cnt=0;
    else cnt=1;
  }
  else cnt=(b-a)*(n-2)+1;
  printf("%ld",cnt);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld %ld",&n,&a,&b);
   ^