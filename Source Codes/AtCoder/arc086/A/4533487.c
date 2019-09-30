#include<stdio.h>
#include<stdlib.h>
#define TYPE int
int cmp_r(const void *a, const void *b) { return *(TYPE *)b - *(TYPE *)a; }
int f[200002];
int main() {
	int N, K, A;
	int type = 0, ans = 0;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A);
		if (f[A] == 0)//shurui
		{
			type++;
		}
		f[A]++;//kazu
	}
	//printf("%d ", type);

	qsort(f, 200000, sizeof(int), cmp_r);
	//for (int i = 0; i < 200000; i++)
	//{
	//	printf("%d ", f[i]);
	//}
	for (int i = type - 1; i > K - 1; i--)
	{
		ans += f[i];
	}
	printf("%d\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A);
   ^