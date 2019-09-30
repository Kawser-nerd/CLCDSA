#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define INF 10000000000
#define M 1000000007
 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
 
int main() {
	long N;
	long T[200001];
	long A[200001];
	long ans = 0;
	long t = 1, a = 1;
	long b;
	long x, y;
	long i, j;
	
	scanf("%ld", &N);
	for(i=1;i<=N;i++) {
		scanf("%ld %ld", &T[i], &A[i]);
		x = t; y = a;
		t = T[i]; a = A[i];
		b = max(max(x/t, y/a), 2);
		while(x > t || y > a) {
			t = T[i] * b;
			a = A[i] * b;
			b++;
		}
	}
	
	printf("%ld\n", t + a);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &N);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld", &T[i], &A[i]);
   ^