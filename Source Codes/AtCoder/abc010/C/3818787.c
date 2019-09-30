#include<stdio.h>
int A, B, C, D, T, V, N, X, Y, i;
long long int a, b;
int main(){
	scanf("%d%d%d%d%d%d", &A, &B, &C, &D, &T, &V);
	scanf("%d", &N);
	for(i=0; i<N; ++i){
		scanf("%d%d", &X, &Y);
		a = (X-A)*(X-A)+(Y-B)*(Y-B);
		a *= V*V*T*T;
		a <<= 2;
		b = (X-A)*(X-A)+(Y-B)*(Y-B)-(X-C)*(X-C)-(Y-D)*(Y-D);
		b += V*V*T*T;
		b = b*b;
		if(a<=b){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d%d%d", &A, &B, &C, &D, &T, &V);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &X, &Y);
   ^