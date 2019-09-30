#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define INF 10000000000
#define M 1000000007
 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

#define B 310

int main() {
	long N, L, Q;
	long x[100001];
	long i, j, k;
	long a, b, tmp;
	long move1day[100001];
	long moveBday[100001] = {0};
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
		move1day[i] = j;
		right = j;
	}
	
	for(i=1;i<=N;i++) {
		k = i;
		for(j=0;j<B;j++) {
			if(k >= N) break;
			k = move1day[k];
		}
		if(j == B) moveBday[i] = k;
	}
	
	scanf("%ld", &Q);
	for(i=1;i<=Q;i++) {
		scanf("%ld %ld", &a, &b);
		
		if(a > b) { tmp = a; a = b; b = tmp; }
		
		j = a;
		while(moveBday[j] > 0 && moveBday[j] < b) {
			j = moveBday[j];
			ans[i] += B;
		}
		
		for(;j<b;) {
			j = move1day[j];
			ans[i]++;
		}
	}
	
	for(i=1;i<=Q;i++) printf("%ld\n", ans[i]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &N);
  ^
./Main.c:25:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=1;i<=N;i++) scanf("%ld", &x[i]);
                    ^
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &L);
  ^
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &Q);
  ^
./Main.c:51:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld", &a, &b);
   ^