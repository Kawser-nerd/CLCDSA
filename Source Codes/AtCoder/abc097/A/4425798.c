#include <stdio.h>
int main(void){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if((abs(c-b)<=d && abs(b-a)<=d) || abs(c-a)<=d) printf("Yes\n");
	else printf("No\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:6: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
  if((abs(c-b)<=d && abs(b-a)<=d) || abs(c-a)<=d) printf("Yes\n");
      ^
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&a,&b,&c,&d);
  ^