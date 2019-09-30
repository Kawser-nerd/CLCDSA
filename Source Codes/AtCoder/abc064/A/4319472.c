#include <stdio.h>
int main(){
  int r,g,b;
  scanf("%d%d%d",&r,&g,&b);
  if ((g*10+b)%4==0){
    printf("YES\n");
  }
  else{
    printf("NO\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&r,&g,&b);
   ^