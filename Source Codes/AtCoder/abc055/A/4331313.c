#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	long long s;
	s=N*800;
	long long z;
	z=N/15*200;
	s-=z;
	printf("%lld",s);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^