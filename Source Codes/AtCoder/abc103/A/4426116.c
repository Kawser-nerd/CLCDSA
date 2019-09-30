#include <stdio.h>
int main(void){
	int a,b,c,cost;
	scanf("%d%d%d",&a,&b,&c);
	if(a<=b && a<=c){
		if(b<=c) cost=c-a;
		else cost=b-a;
	}
	else if(b<=c && b<=a){
		if(c<=a) cost=a-b;
		else cost=c-b;
	}
	else{
		if(a<=b) cost=b-c;
		else cost=a-c;
	}
	printf("%d\n",cost);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^