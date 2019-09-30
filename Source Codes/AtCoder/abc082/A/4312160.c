#include <stdio.h>
int main(){
	int a,b,x;
	scanf("%d %d",&a,&b);
	if ( ( a + b ) % 2 == 1 ) {
		x = ( a + b + 1 ) / 2;
	} else {
		x = ( a + b ) / 2;
	}
	printf("%d",x);
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^