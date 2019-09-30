#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if(abs(a-b)%2==0)puts("Alice");
	else puts("Borys");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&a,&b);
  ^