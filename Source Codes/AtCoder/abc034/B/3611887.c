#include <stdio.h>

int main(){
	long a;
	scanf("%ld",&a);
	if(a%2==0)a--;
	else a++;
	printf("%ld\n",a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&a);
  ^