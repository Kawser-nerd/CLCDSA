#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define sl(x) scanf("%ld", &x)
#define ss(x) scanf("%s", x)
#define pl(x) printf("%ld\n", x)
#define ps(x) printf("%s\n", x)
 
#define INF 1000000000000000000
#define MOD 1000000007
 
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct {
	long id;
	long par;
	long cnt;
	long need;
	long *counts;
	long clen;
} Data;

long N, M;
long A[100001];
Data data[100001];
long list[100001];
long len = 0;

int compare_long(const void *a, const void *b) {
	return *(long*)b - *(long*)a;
}

int main() {
	long i, j;
	long ans = 0;
	long idx = 0;
	long id, par;
	
	sl(N);
	for(i=1;i<=N;i++) {
		data[i].id = i;
		data[i].par = -1;
		data[i].cnt = 0;
		data[i].need = 0;
		data[i].clen = 0;
	}
	for(i=2;i<=N;i++) {
		sl(A[i]);
		data[i].par = A[i];
		data[A[i]].need++;
	}
	for(i=1;i<=N;i++) {
		data[i].counts = (long *)malloc(sizeof(long) * (data[i].need + 1));
	}
	
	for(i=2;i<=N;i++) {
		if(data[i].need == 0) {
			list[len++] = i;
		}
	}
	while(idx < len) {
		id = list[idx++];
		par = data[id].par;
		
		data[par].counts[data[par].clen++] = data[id].cnt + 1;
		
		if(data[par].clen == data[par].need) {
			qsort(data[par].counts, data[par].clen, sizeof(long), compare_long);
			for(i=0;i<data[par].clen;i++) {
				data[par].cnt = MAX(data[par].cnt, data[par].counts[i] + i);
			}
			if(par == 1) break;
			list[len++] = par;
		}
	}
	
	pl(data[1].cnt);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:42:2: note: in expansion of macro ‘sl’
  sl(N);
  ^
./Main.c:6:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define sl(x) scanf("%ld", &x)
               ^
./Main.c:51:3: note: in expansion of macro ‘sl’
   sl(A[i]);
   ^