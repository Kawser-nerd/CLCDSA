#include <stdio.h>

int main(){
	int a,b;
  scanf("%d %d ",&a,&b);
  a = a > 0 ? a : -a;
  b = b > 0 ? b : -b;
  if(a==b)printf("Draw\n");
  else if(a > b) printf("Bug\n");
  else printf("Ant\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d ",&a,&b);
   ^