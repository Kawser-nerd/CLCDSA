#include <stdio.h>
#include <stdlib.h>

#define getchar getchar_unlocked
#define putchar putchar_unlocked

static inline int nextInt(void) {
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

static inline void printInt(int x) {
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

typedef struct {
	int x, idx;
} Rec;

int compare(const void *a, const void *b) {
	return ((const Rec *)a)->x - ((const Rec *)b)->x;
}

Rec a[100000];
int ans[100000];

int main(void) {
	int n;

	n = nextInt();
	for (int i = 0; i < n; i++)
		a[i] = (Rec){nextInt(), i};

	qsort(a, n, sizeof(Rec), &compare);

	int num = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i].x != a[i - 1].x)
			num++;
		ans[a[i].idx] = num;
	}

	for (int i = 0; i < n; i++) {
		printInt(ans[i]);
		putchar('\n');
	}

	return 0;
}