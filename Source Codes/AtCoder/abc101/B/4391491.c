#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main(void){
  int n,sn=0;
  scanf("%d",&n);
  int tmp=n;
  while(tmp!=0){
    sn+=tmp%10;
    tmp/=10;
  }
  if(n%sn==0) printf("Yes");
  else printf("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^