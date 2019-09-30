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
	long N;
	long x;
	long ans[300001];
	int i, j;
	int tmp;
	
	sl(N); sl(x);
	for(i=1;i<2*N;i++) ans[i] = i;
	
	if(x == 1 || x == 2 * N - 1) {
		printf("No\n");
		return 0;
	}
	
	printf("Yes\n");
	if(x == N - 1) {
		ans[N-2] = N;
		ans[N] = N-2;
	} else if(x == N + 1) {
		ans[N+2] = N;
		ans[N] = N+2;
	} else if(x < N) {
		ans[x-1] = N-1;
		ans[x] = N;
		ans[N-1] = x-1;
		ans[N] = x;
	} else {
		ans[x] = N;
		ans[x+1] = N+1;
		ans[N] = x;
		ans[N+1] = x+1;
	}
	
	for(i=1;i<2*N;i++) pl(ans[i]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:23:2: note: in expansion of macro ‘sl’
  sl(N); sl(x);
  ^
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:23:9: note: in expansion of macro ‘sl’
  sl(N); sl(x);
         ^