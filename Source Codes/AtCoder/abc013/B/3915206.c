#include <stdio.h>

int main(){
	int a, b;
	int diff;
	scanf("%d\n%d", &a, &b);
	if(a < b){
		diff = b - a;
	}else{
		diff = a - b;
	}
	printf("%d\n", diff < 10 - diff ? diff : 10 - diff);
	//printf("%d\n", diff % 6);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n%d", &a, &b);
  ^