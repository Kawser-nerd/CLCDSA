#include<stdio.h>

long A[100001];
long d[100001];
long s;
long N;
long num;

long sum(long n){
	return n*(n+1)/2;
}

void input(){
	int i;
	s = 0;
	scanf("%ld", &N);
	for( i = 0; i < N; i++ ){
		scanf("%ld", &A[i]);
		s += A[i];
	}
	num = s / sum(N);
	return;
}

int check(){
	int i;
	long j = 0;
	for( i = 0; i < N-1; i++ ){ d[i] = num - (A[i+1] - A[i]); }
	d[N-1] = num - (A[0] - A[N-1]);
	for( i = 0; i < N; i++ ){
		if( d[i] < 0 ){ return 0; }
		if( d[i] % N != 0 ){ return 0; }
		j += d[i] / N;
	}
	if( j != num ){ return 0; }
	return 1;
}

int main(){
	input();
	if( s % sum(N) != 0 ){ printf("NO\n"); return 0; }
	if( check() == 0 ){ printf("NO\n"); return 0; }
	printf("YES\n");
	return 0;
} ./Main.c: In function ‘input’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &N);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &A[i]);
   ^