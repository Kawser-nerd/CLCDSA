#include <stdio.h>
#include <stdlib.h>

#define getchar getchar_unlocked
#define putchar putchar_unlocked

inline int nextInt(void) {
	int ch;
	int minus, x;

	do {
		ch = getchar();
	} while (ch < '-');

	if (ch == '-') {
		minus = 1;
		ch = getchar();
	} else
		minus = 0;

	x = 0;
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch & 15);
		ch = getchar();
	}

	return minus ? -x : x;
}

inline void printInt(int x) {
	char ch[10];
	int cnt;

	if (x < 0) {
		putchar('-');
		x = -x;
	}

	cnt = 0;
	do {
		ch[cnt++] = '0' | x % 10;
		x /= 10;
	} while (x);

	while (cnt--)
		putchar(ch[cnt]);
}

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

	n = nextInt();
	for (int i = 0; i < n; i++)
		a[i] = b[i] = nextInt();

	qsort(b, n, sizeof(int), &compare);
	m = unique(b, n);

	for (int i = 0; i < n; i++) {
		printInt(binarySearch(b, m, a[i]));
		putchar('\n');
	}

	return 0;
}