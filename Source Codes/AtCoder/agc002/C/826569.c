#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define INF 1000000000
 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int N, L;
	int a[100001];
	int i, j;
	int left, right;
	
	scanf("%d %d", &N, &L);
	for(i=1;i<=N;i++) {
		scanf("%d", &a[i]);
	}
	
	for(i=1;i<=N-1;i++) {
		if(a[i] + a[i+1] >= L) {
			left = i;
			break;
		}
	}
	if(i == N) {
		printf("Impossible\n");
		return 0;
	}
	
	
	printf("Possible\n");
	for(i=1;i<left;i++) {
		printf("%d\n", i);
	}
	for(i=N-1;i>=left;i--) {
		printf("%d\n", i);
	}
	
	/*
	left = 1;
	right = N;
	for(i=1;i<=N-1;i++) {
		if(a[left] < a[right]) {
			printf("%d\n", left++);
		} else {
			printf("%d\n", --right);
		}
	}
	*/
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &L);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^