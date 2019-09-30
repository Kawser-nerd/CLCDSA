#include <stdio.h>

int main(){
	int N, h, m, s;
	scanf("%d", &N);
	s = N % 60;
	N /= 60;
	m = N % 60;
	h = N / 60;
	printf("%02d:%02d:%02d\n", h, m, s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^