#include <stdio.h>
 
int main(void){
  char N[5];
  int i;
  scanf("%s",N);
  if(N[0] == N[2]){
    printf("Yes\n");
  }
  else{
    printf("No\n");
  }
    return 0;
  } ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",N);
   ^