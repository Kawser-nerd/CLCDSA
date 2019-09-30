#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
#define INF 1000000000
 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
 
typedef struct {
	int a;
	int b;
	int dif;
} Magic;
 
int comp_d(const void *c1, const void *c2) {
	Magic d1 = *(Magic *)c1;
	Magic d2 = *(Magic *)c2;
	int t1 = d1.a;
	int t2 = d2.a;
	
	return t1 - t2;
}
 
int comp_u(const void *c1, const void *c2) {
	Magic d1 = *(Magic *)c1;
	Magic d2 = *(Magic *)c2;
	int t1 = d1.b;
	int t2 = d2.b;
	
	return t2 - t1;
}
 
int main() {
	int N;
	Magic dm[100000];
	Magic um[100000];
	Magic em[100000];
	int d = 0, u = 0, e = 0;
	int i;
	long t = 0;
	long ans = 0;
	int a, b;
	
	scanf("%d", &N);
	for(i=0;i<N;i++) {
		scanf("%d %d", &a, &b);
		if(a - b < 0) {
			dm[d].a = a;
			dm[d].b = b;
			dm[d++].dif = a - b;
		} else if(a - b > 0){
			um[u].a = a;
			um[u].b = b;
			um[u++].dif = a - b;
		} else {
			em[e].a = a;
			em[e].b = b;
			em[e++].dif = a - b;
		}
	}
	
	qsort((void *)dm, d, sizeof(Magic), comp_d);
	qsort((void *)um, u, sizeof(Magic), comp_u);
	
	for(i=0;i<d;i++) {
		t += dm[i].a;
		ans = max(ans, t);
		t -= dm[i].b;
	}
	
	for(i=0;i<e;i++) {
		t += em[i].a;
		ans = max(ans, t);
		t -= em[i].b;
	}
	
	for(i=0;i<u;i++) {
		t += um[i].a;
		ans = max(ans, t);
		t -= um[i].b;
	}
	
	printf("%ld\n", ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &a, &b);
   ^