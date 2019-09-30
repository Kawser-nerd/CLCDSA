#include <stdio.h>
int main(void){
	int a,b,c;
	scanf("%d%d",&a,&b);
	if(a<b) c=b-a;
	else c=a-b;
	if(c>5) c=10-c;
	printf("%d\n",c);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^