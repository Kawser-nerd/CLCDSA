#include <stdio.h>

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N;
	scanf("%d", &N);
	printf("%d\n", 100 * (N / 10) + min(15 * (N % 10), 100));
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^