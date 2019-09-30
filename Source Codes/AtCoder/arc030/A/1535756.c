#include<stdio.h>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%s\n",a<b*2?"NO":"YES");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^