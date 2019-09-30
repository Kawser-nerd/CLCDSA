#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define INF 10000000000
#define M 1000000007

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	long N, L, Q;
	long x[100001];
	long i, j, k;
	long a, b, tmp;
	long move[100001];
	long move100[100001];
	long right;
	long ans[100001] = {0};
	
	scanf("%ld", &N);
	for(i=1;i<=N;i++) scanf("%ld", &x[i]);
	scanf("%ld", &L);
	
	right = 2;
	for(i=1;i<=N;i++) {
		for(j=right;j<=N;j++) {
			if(x[j] - x[i] > L) {
				j--;
				break;
			}
		}
		if(j > N) j = N;
		move[i] = j;
		right = j;
	}
	
	for(i=1;i<=N;i++) {
		k = i;
		for(j=0;j<100;j++) {
			if(k >= N) break;
			k = move[k];
		}
		if(j >= 100) move100[i] = k;
		else move100[i] = -1;
	}
	
	scanf("%ld", &Q);
	for(i=1;i<=Q;i++) {
		scanf("%ld %ld", &a, &b);
		if(a > b) {
			tmp = a;
			a = b;
			b = tmp;
		}
		if(L == 1) {
			ans[i] = b - a;
			continue;
		}
		
		j = a;
		while(move100[j] != -1 && move100[j] < b) {
			j = move100[j];
			ans[i] += 100;
		}
		
		for(;j<b;) {
			j = move[j];
			ans[i]++;
		}
	}
	
	for(i=1;i<=Q;i++) printf("%ld\n", ans[i]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &N);
  ^
./Main.c:23:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=1;i<=N;i++) scanf("%ld", &x[i]);
                    ^
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &L);
  ^
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &Q);
  ^
./Main.c:51:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld", &a, &b);
   ^