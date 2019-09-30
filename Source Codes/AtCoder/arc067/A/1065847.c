#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define sl(x) scanf("%ld", &x)
#define ss(x) scanf("%s", x)
#define pl(x) printf("%ld\n", x)
#define ps(x) printf("%s\n", x)
 
#define INF 100000000000
#define MOD 1000000007
 
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int main() {
	long N;
	long i, j;
	long table[1001] = {0};
	long ans = 1;
	long tmp;
	
	sl(N);
	
	if(N == 1) {
		pl(1);
		return 0;
	}
	
	for(i=2;i<=N;i++) {
		tmp = i;
		for(j=2;j<=i;j++) {
			if(tmp < j) break;
			while(tmp % j == 0) {
				table[j]++;
				tmp /= j;
			}
		}
	}
	
	for(i=2;i<=N;i++) {
		ans *= (table[i] + 1);
		ans %= MOD;
	}
	
	pl(ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:22: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘int’ [-Wformat=]
 #define pl(x) printf("%ld\n", x)
                      ^
./Main.c:27:3: note: in expansion of macro ‘pl’
   pl(1);
   ^
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:24:2: note: in expansion of macro ‘sl’
  sl(N);
  ^