#include <stdio.h>
int main(){
  int a,b,c,d,e,f;
  scanf ("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
  printf ("%d\n",(a/10*b)+(c/10*d)+(e/10*f));
  return 0;
	} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
   ^