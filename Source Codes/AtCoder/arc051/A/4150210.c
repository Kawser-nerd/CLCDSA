#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int x1, y1, r, x2, y2, x3, y3;

  scanf("%d%d%d%d%d%d%d", &x1, &y1, &r, &x2, &y2, &x3, &y3);

  if((y2 <= y1 - r) && (y3 >= y1 + r) && (x2 <= x1 - r) && (x3 >= x1 + r)){
    printf("NO\n");
    printf("YES\n");
  }else if((((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) <= r * r) && (((x1 - x3) * (x1 - x3) + (y1 - y2) * (y1 - y2)) <= r * r) && (((x1 - x2) * (x1 - x2) + (y1 - y3) * (y1 - y3)) <= r * r) && (((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)) <= r * r)){
    printf("YES\n");
    printf("NO\n");
  }else{
    printf("YES\n");
    printf("YES\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d%d%d", &x1, &y1, &r, &x2, &y2, &x3, &y3);
   ^