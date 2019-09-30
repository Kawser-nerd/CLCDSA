#include <stdio.h>
#include <string.h>
int main(){
  int a, b, c;

  scanf("%d%d%d", &a, &b, &c);

  if(c >= a && c <= b){
    printf("Yes");
  }else{
    printf("No");
  }

  printf("\n");
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &a, &b, &c);
   ^