#include <stdio.h>
int main() {
  int ab, bc, ca,area;
  scanf("%d %d %d",&ab,&bc,&ca);
  area = ab * bc / 2;
  printf("%d",area);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&ab,&bc,&ca);
   ^