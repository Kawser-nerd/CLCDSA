#include <stdio.h>

int main () {
  int x;
  scanf("%d",&x);
  
  if ((x==3)|(x==5)|(x==7)){
  	printf("YES");
  }
  else{
    printf("NO");
  }  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x);
   ^