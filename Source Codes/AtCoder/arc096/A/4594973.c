#include<stdio.h>
#include <limits.h>  
#define inf (INT_MAX-1)
int Max(int a, int b) { if (a>b) { return a; }return b; }
int Min(int a, int b) { if (a<b) { return a; }return b; }
int main() {
	int A, B, C, X, Y;
	int tmp,ans=inf;
	scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y);

	for (int i = 0; i <= 100000; i++)
	{
		tmp = i * 2 * C + Max(0, X - i)*A + Max(0, Y - i)*B;
		ans = Min(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y);
  ^