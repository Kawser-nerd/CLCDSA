#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define INF 1000000000
 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	long N, K;
	long ans = 0;
	char D[11][4];
	long i, j;
	char buf[100];
	
	scanf("%ld %ld", &N, &K);
	for(i=1;i<=K;i++) {
		scanf("%s", D[i]);
	}
	
	ans = N;
	while(1) {
		sprintf(buf, "%ld", ans);
		for(i=1;i<=K;i++) {
			if(strstr(buf, D[i]) != NULL) break;
		}
		if(i > K) break;
		ans++;
	}
	
	printf("%ld\n", ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld", &N, &K);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", D[i]);
   ^