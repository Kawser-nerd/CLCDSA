#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  int H1, W1, H2, W2;

  scanf("%d%d%d%d", &H1, &W1, &H2, &W2);

  if((H1 == H2) || (H1 == W2) || (W1 == H2) || (W1 == W2)){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d", &H1, &W1, &H2, &W2);
   ^