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

typedef struct data {
	long id;
	long num;
} DATA;

DATA yama[100010];

long N, M;
long a[300001];
long ans[100010] = {0};

int compare_long(const void *a, const void *b) {
	return *(long*)a - *(long*)b;
}

int comp_yama(const void *c1, const void *c2) {
	DATA d1 = *(DATA *)c1;
	DATA d2 = *(DATA *)c2;
	int t1 = d1.num;
	int t2 = d2.num;
	
	return t2 - t1;
}

int main() {
	long i, j;
	long min_id;
	long pre = 0;
	long sum = 0;
	
	sl(N);
	
	for(i=0;i<N;i++) {
		sl(yama[i].num);
		yama[i].id = i + 1;
	}
	
	qsort((void *)yama, N, sizeof(DATA), comp_yama);
	
	min_id = yama[0].id;
	for(i=1;i<N;i++) {
		sum += i * (yama[i-1].num - yama[i].num);
		ans[min_id] += i * (yama[i-1].num - yama[i].num);
		if(min_id > yama[i].id) {
			min_id = yama[i].id;
		}
	}
	ans[min_id] += i * yama[i-1].num;
	
	for(i=1;i<=N;i++) {
		pl(ans[i]);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:48:2: note: in expansion of macro ‘sl’
  sl(N);
  ^
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:51:3: note: in expansion of macro ‘sl’
   sl(yama[i].num);
   ^