#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int y, m, d;
  int p;

  scanf("%d%d%d", &y, &m, &d);

  if(m <= 2){
    m += 12;
    y -= 1;
  }

  p = (365 * y) + (y / 4) - (y / 100) + (y / 400) + (306 * (m + 1) / 10) + d - 429;

  printf("%d\n", 735369 - p);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &y, &m, &d);
   ^