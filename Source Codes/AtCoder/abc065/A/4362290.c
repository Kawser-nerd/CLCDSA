# include <stdio.h>

int main(){
  int x,a,b;
  scanf("%d %d %d",&x,&a,&b);
  if(b<=a) puts("delicious");
  else if(b<=a+x) puts("safe");
  else puts("dangerous");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&x,&a,&b);
   ^