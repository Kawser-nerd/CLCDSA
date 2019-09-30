#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define sl(x) scanf("%ld", &x)
#define ss(x) scanf("%s", x)
#define pl(x) printf("%ld\n", x)
#define pd(x) printf("%lf\n", x)
#define ps(x) printf("%s\n", x)
 
#define INF 1000000000000000000
#define MOD 1000000007
 
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int compare_long(const void *a, const void *b) {
	return *(long*)a - *(long*)b;
}

int main() {
	long N;
	long a;
	long b[100001] = {0};
	long cnt = 0;
	long i, j;
	long ans = 0;
	
	sl(N);
	for(i=1;i<=N;i++) {
		sl(a);
		b[a]++;
	}
	
	for(i=1;i<=100000;i++) {
		if(b[i] > 0) {
			cnt += b[i] - 1;
			ans++;
		}
	}
	
	pl(cnt % 2 ? ans - 1 : ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:30:2: note: in expansion of macro ‘sl’
  sl(N);
  ^
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:32:3: note: in expansion of macro ‘sl’
   sl(a);
   ^