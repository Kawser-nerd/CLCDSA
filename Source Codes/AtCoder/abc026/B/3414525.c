#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int compare_int(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}
int main()
{
	int	n;
	int	r[1010];
	int	i;
	double	s = 0.0;

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &r[i]);
	}

	qsort(r, n, sizeof(int), compare_int);

	for (i = 0; i < n; ++i) {
		if ((i % 2) == 0) {
			s += M_PI * (double)r[i] * (double)r[i];
		}
		else {
			s -= M_PI * (double)r[i] * (double)r[i];
		}
	}
	printf("%0.10f\n", s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &r[i]);
   ^