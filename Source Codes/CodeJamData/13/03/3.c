#include <stdio.h>

enum { MAX_DIGITS = 26 };
enum { MAX_BM = 1 << MAX_DIGITS };

void print(int bm, int len)
{
	for (int i = 0; i < len; ++i, bm /= 2)
		putchar('0' + bm%2);
}

int rev(int bm, int len)
{
	int r = 0;
	for (int i = 0; i < len; ++i, bm /= 2)
		r = r*2 + bm%2;
	return r;
}

int main(void)
{
	puts("1\n2\n3");
	for (int i = 2; i <= 2*MAX_DIGITS+1; ++i) {
		putchar('2');
		for (int j = 0; j < i-2; ++j)
			putchar('0');
		putchar('2');
		putchar('\n');
		if (i%2 == 1) {
			putchar('2');
			for (int j = 0; j < i/2-1; ++j)
				putchar('0');
			putchar('1');
			for (int j = 0; j < i/2-1; ++j)
				putchar('0');
			putchar('2');
			putchar('\n');
		}
	}
	for (int bm = 1; bm < MAX_BM; ++bm) {
		int one_count = __builtin_popcount(bm);
		if (one_count >= 5)
			continue;
		int len = 32 - __builtin_clz(bm);
		print(rev(bm, len), len);
		print(bm, len);
		putchar('\n');
		for (int i = 0; i <= 2; ++i) {
			if (2*one_count + i*i >= 10)
				continue;
			print(rev(bm, len), len);
			putchar('0' + i);
			print(bm, len);
			putchar('\n');
		}
	}
	return 0;
}
