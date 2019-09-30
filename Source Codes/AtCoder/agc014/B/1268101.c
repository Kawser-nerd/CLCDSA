#include <stdio.h>

int a[100005];
int b[100005];
int sum[100005];

int main() {

	int N, M;

	scanf("%d %d",&N,&M);

	int i;

	for (i = 0; i < M; i++) {
		scanf("%d %d",&a[i],&b[i]);
		sum[a[i]]++;
		sum[b[i]]++;
	}

	for (i = 1; i <= N; i++) {
		if (sum[i] % 2 == 1) { 
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a[i],&b[i]);
   ^