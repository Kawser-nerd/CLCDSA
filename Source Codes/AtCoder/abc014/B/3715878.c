#include<stdio.h>
int N, A, Ans, i;
long long X;
int main(){
	scanf("%d%lld", &N, &X);
	for(i=0; i<N; i++){
		scanf("%d", &A);
		Ans += A*(X & 1);
		X >>= 1;
	}
	printf("%d\n", Ans);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%lld", &N, &X);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A);
   ^