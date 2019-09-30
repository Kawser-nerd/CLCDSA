#include <stdio.h>
#include <math.h>

float distance(int a, int b, int c, int d)
{
	return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}

int factorial(int n)
{
	if (n > 0)
		return n*factorial(n-1);
	else if (n == 0)
		return 1;
}

int main()
{
	int N;
	scanf("%d", &N);
	int x[N], y[N];
	int i, j;
	for (i = 0; i < N; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}//?????
	float max=0.0;
	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			if (max < distance(x[i], y[i], x[j], y[j])) {
				max = distance(x[i], y[i], x[j], y[j]);
			}
		}
	}
	printf("%8.6f\n", max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &x[i], &y[i]);
   ^