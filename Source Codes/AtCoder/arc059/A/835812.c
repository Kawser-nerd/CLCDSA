#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
#define INF 10000000000
 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int compare_long(const void *a, const void *b) {
	return *(long*)a - *(long*)b;
}

int main() {
	long N;
	long i, j;
	long ans = INF;
	long tmp;
	long data[100001];
	long a[101];
	
	scanf("%ld", &N);
	for(i=0;i<N;i++) {
		scanf("%ld", &a[i]);
	}
	
	for(i=-100;i<=100;i++) {
		tmp = 0;
		for(j=0;j<N;j++) {
			tmp += (i - a[j]) * (i - a[j]);
		}
		ans = min(ans, tmp);
	}
	
	printf("%ld\n", ans);
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &N);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &a[i]);
   ^