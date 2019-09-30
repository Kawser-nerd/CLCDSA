#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

static const int primes[] = { 2, 3, 5, 7 };

int test(unsigned int x, unsigned int b, unsigned int d)
{
	int p = 1;
	int r = 0;
	while (x) {
		if (x & 1)
			r += p;
		p *= b;
		if (p > d)
			p %= d;
		x >>= 1;
	}

	return (r % d) == 0;
}

int goodb(unsigned int x, unsigned int b)
{
	for (int i = 0; i < sizeof(primes)/sizeof(primes[0]); i++)
		if (test(x, b, primes[i]))
			return primes[i];
	return 0;
}

int good(unsigned int x, unsigned int *divs)
{
	for (int i = 2; i <= 10; i++)
		if (!(divs[i] = goodb(x, i)))
			return 0;
	return 1;
}

int main(int argc, const char* argv[])
{
	unsigned int r;
	unsigned int divs[11];

	printf("Case #1:\n");

	while (1) {
		r = (rand() << 1) + 1;
		r |= (1U << 31);
		//r = (r & 0xFFFF);
		//r |= (1U << 15);
		if (good(r, divs)) {
			for (int i = 31; i >= 0; i--)
				putchar((r & (1U << i)) ? '1' : '0');
			for (int i = 2; i <= 10; i++)
				printf(" %u", divs[i]);
			printf("\n");
		}
	}
	return 0;
}
