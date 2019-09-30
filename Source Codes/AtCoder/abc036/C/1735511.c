#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	return *(const int *)a - *(const int *)b;
}

int unique(int a[], int n) {
	int i = 0;
	for (int j = 1; j < n; j++)
		if (a[j] != a[i])
			a[++i] = a[j];

	return n > 0 ? i + 1 : 0;
}

int binarySearch(const int data[], int n, int key) {
	int l = 0, r = n - 1;

	while (l <= r) {
		const int m = (l + r) / 2;

		if (data[m] == key)
			return m;
		else if (data[m] > key)
			r = m - 1;
		else
			l = m + 1;
	}

	return -1;
}

int a[100000], b[100000];

int main(void) {
	int n;
	int m;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		b[i] = a[i];
	}

	qsort(b, n, sizeof(int), &compare);
	m = unique(b, n);

	for (int i = 0; i < n; i++)
		printf("%d\n", binarySearch(b, m, a[i]));

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:40:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:42:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", a + i);
   ^