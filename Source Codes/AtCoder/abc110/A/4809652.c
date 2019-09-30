#include <stdio.h>
int main(void){
	int a,b,c;
	int temp;
	scanf("%d %d %d",&a,&b,&c);
	//abc???????????
	if ( a<b){
		temp = a;
		a = b;
		b = temp;
	}
	if ( a<c){
		temp = a;
		a = c;
		c = temp;
	}
	printf("%d",(a*10)+b+c);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^