#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long ary[50], tmp[50];
int flag[50];
int idx_stack[10000];
int sp;

int compare(const void *a, const void *b) {
	long long ta = *(const long long *)a, tb = *(const long long *)b;
	if (ta == tb)
		return 0;
	if (ta < tb)
		return -1;
	return 1;
}

int fastPowSca(long long x, long long n) {
	long long prod = 1;

	while (n) {
		if (n & 1) {
			prod *= x;
			prod %= MOD;
		}
		x *= x;
		x %= MOD;

		n >>= 1;
	}

	return prod;
}

int main(void) {
	int i;
	int n;
	long long a, b;

	scanf("%d %lld %lld", &n, &a, &b);
	for (i = 0; i < n; i++) {
		scanf("%lld", ary + i);
		tmp[i] = ary[i];
	}

	if (a == 1) {
		qsort(ary, n, sizeof(long long), &compare);

		for (i = 0; i < n; i++)
			printf("%lld\n", ary[i]);
	} else {
		while (1) {
			int ok;
			long long min;
			int minIdx;

			ok = 1;
			for (i = 0; i < n; i++)
				ok &= flag[i];
			if (ok)
				break;

			min = 2e18;
			for (i = 0; i < n; i++)
				if (tmp[i] < min) {
					min = tmp[i];
					minIdx = i;
				}

			flag[minIdx] = 1;
			tmp[minIdx] *= a;
			idx_stack[sp++] = minIdx;
		}

		if (b < sp - n) {
			for (i = 0; i < b; i++)
				ary[idx_stack[i]] *= a;

			qsort(ary, n, sizeof(long long), &compare);

			for (i = 0; i < n; i++)
				printf("%lld\n", ary[i] % MOD);
		} else {
			const int loop = (b - (sp - n)) / n;
			const int rest = (b - (sp - n)) % n;
			const int powa = fastPowSca(a, loop);

			for (i = 0; i < sp - n; i++) {
				ary[idx_stack[i]] *= a;
				ary[idx_stack[i]] %= MOD;
			}

			for (i = 0; i < n; i++) {
				ary[i] *= powa;
				ary[i] %= MOD;
			}

			for (i = 0; i < rest; i++) {
				ary[idx_stack[sp - n + i]] *= a;
				ary[idx_stack[sp - n + i]] %= MOD;
			}

			for (i = rest; i < n; i++)
				printf("%lld\n", ary[idx_stack[sp - n + i]]);
			for (i = 0; i < rest; i++)
				printf("%lld\n", ary[idx_stack[sp - n + i]]);
		}
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %lld %lld", &n, &a, &b);
  ^
./Main.c:44:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", ary + i);
   ^