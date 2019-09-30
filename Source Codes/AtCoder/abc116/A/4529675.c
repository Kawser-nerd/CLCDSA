#include <stdio.h>
#include <string.h>
int main() {
  int AB;
  int BC;
  int CA;
  scanf("%d %d %d",&AB,&BC,&CA);
  int surface =	(AB*BC)/2;
  printf("%d\n",surface);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&AB,&BC,&CA);
   ^