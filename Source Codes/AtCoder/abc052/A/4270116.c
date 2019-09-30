#include<stdio.h>
#include<math.h>
#include<string.h>
int main() {
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	int x,y;
	x=a*b;
	y=c*d;
	if(x>y){
		printf("%d",x);
	}else{
		printf("%d",y);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&a,&b,&c,&d);
  ^