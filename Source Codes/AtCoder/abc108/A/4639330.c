#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int main(void){
  int i,j,n,odd=0,even=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    if(i%2==0) even++;
    else odd++;
  }
  printf("%d",even*odd);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^