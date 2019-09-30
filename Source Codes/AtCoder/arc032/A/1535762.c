#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	printf("%s\n",n-2?"BOWWOW":"WANWAN");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^