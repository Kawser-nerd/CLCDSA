#include <stdio.h>
#include <string.h>

int main(void)
{
	int a,b,x;
	scanf("%d%d%d",&a,&b,&x);
	if(a<=x && x<=a+b){printf("YES");}
	else{printf("NO");}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&x);
  ^