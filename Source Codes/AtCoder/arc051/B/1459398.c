#include <stdio.h>

int main(){
	int K, a, b;
	scanf("%d", &K);
	for(a = 1, b = 1; K > 1; K--){
		a = a + b;
		b = a - b;
	}
	printf("%d %d\n", b, a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &K);
  ^