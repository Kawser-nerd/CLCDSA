#include <stdio.h>
#include <string.h>

int main(){
  int a,b;
  scanf("%d\n%d",&a,&b);
  if(a%b == 0)printf("0\n");
  else printf("%d\n",b-a%b);
  return 0;
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d\n%d",&a,&b);
   ^