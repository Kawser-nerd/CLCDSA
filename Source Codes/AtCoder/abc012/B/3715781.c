#include<stdio.h>
int N, h, m, s;
int main(){
	scanf("%d", &N);
	s = N % 60;
	N /= 60;
	m = N % 60;
	N /= 60;
	h = N;
	printf("%02d:%02d:%02d\n", h, m, s);
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^