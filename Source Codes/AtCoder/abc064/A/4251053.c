#include <stdio.h>

int main(void){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);

  a = a*100+b*10+c;
  if(a%4 == 0) printf("YES\n");
  else printf("NO\n");

  return 0;
} ./Main.c: In function �main�:
./Main.c:5:3: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^