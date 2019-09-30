#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare_int(const void *a, const void *b)
{
	// ?? 
	return *(int *) b - *(int *) a;
}

int main(int argc, char *argv[])
{
	int n, i, c;
	int j;
	int a[200000];
	
	int x, y;
	int min_sq, l_min_sq;
	
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	qsort(a, n, sizeof(int), compare_int);

	c = 0;

	l_min_sq = -1;
	for (i = 0; i < n; i++) {
		x = a[i];
		if (x == 0) {continue;}
		min_sq = pow(2, (int) log2(x) + 1);

		if (l_min_sq != min_sq) {
			j = n - 1;
		}
		for (;j > i; j--) {
			y = a[j];
			if (y == 0) {continue;}
			if (y == min_sq - x) {
				a[j] = 0;
				c++;
				break;
			}
			if (y > min_sq - x) {
				break;
			}
		}
		l_min_sq = min_sq;
	}

	printf("%d\n", c);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^