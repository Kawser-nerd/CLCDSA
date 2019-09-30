#include <stdio.h>
#include <string.h>
int main(){
  int x, a , b;
  
  scanf("%d%d%d", &x, &a, &b);

  if((b-a) > x){
    printf("dangerous");
  }else if((b-a) > 0){
    printf("safe");
  }else if((b-a) <= 0){
    printf("delicious");
  }

  printf("\n");

} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &x, &a, &b);
   ^