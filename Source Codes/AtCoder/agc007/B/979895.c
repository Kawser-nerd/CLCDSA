#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define sl(x) scanf("%ld", &x)
#define ss(x) scanf("%s", x)
#define pl(x) printf("%ld\n", x)

#define INF 100000000000
#define M 1000000007

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	long i, j;
	long N;
	long p[20001];
	long a[20001];
	long b[20001];
	long step = 40000;
	
	sl(N);
	for(i=1;i<=N;i++) {
		sl(p[i]);
		b[N-i+1] = a[i] = i * step;
	}
	
	step = N;
	for(i=1;i<=N;i++) {
		a[p[i]] -= step;
		step--;
	}
	
	for(i=1;i<N;i++) {
		printf("%ld ", a[i]);
	}
	printf("%ld\n", a[i]);
	
	for(i=1;i<N;i++) {
		printf("%ld ", b[i]);
	}
	printf("%ld\n", b[i]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:24:2: note: in expansion of macro ‘sl’
  sl(N);
  ^
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:26:3: note: in expansion of macro ‘sl’
   sl(p[i]);
   ^