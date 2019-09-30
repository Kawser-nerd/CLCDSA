#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define sl(x) scanf("%ld", &x)
#define ss(x) scanf("%s", x)
#define pl(x) printf("%ld\n", x)
#define ps(x) printf("%s\n", x)

#define INF 100000000000
#define M 1000000007

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	long N, T;
	long A[100010];
	long i, j;
	long m = INF;
	long min_list[100010];
	long sale_list[100010];
	long ans = 0;
	
	sl(N); sl(T);
	for(i=0;i<N;i++) {
		sl(A[i]);
		m = min(m, A[i]);
		sale_list[i] = (A[i] - m) * (T / 2);
	}
	
	m = sale_list[0];
	for(i=1;i<N;i++) {
		m = max(m, sale_list[i]);
	}
	
	for(i=0;i<N;i++) {
		if(m == sale_list[i]) ans++;
	}
	
	pl(ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:26:2: note: in expansion of macro ‘sl’
  sl(N); sl(T);
  ^
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:26:9: note: in expansion of macro ‘sl’
  sl(N); sl(T);
         ^
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:28:3: note: in expansion of macro ‘sl’
   sl(A[i]);
   ^