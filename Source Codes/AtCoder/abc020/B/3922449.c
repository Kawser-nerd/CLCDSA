#include <stdio.h>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	for(int i = 100; i > 0; i /= 10){
		if(i <= b){
			a *= i * 10;
			break;
		}
	}
	a += b;
	printf("%d\n", a * 2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &a, &b);
  ^