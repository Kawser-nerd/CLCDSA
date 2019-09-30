#include <stdio.h>

int a, b, k, aa[32], bb[32], kk[32];

long long check_sub_sub(void) {
	int i;
	long long ret;

	ret = 1LL;
	for (i = 31; i >= 0; i--)
		if (aa[i] == 0 && bb[i] == 0 && kk[i] == 0)
			;
		else if (aa[i] == 0 && bb[i] == 0 && kk[i] == 1)
			return 0LL;
		else if (aa[i] == 0 && bb[i] == 0 && kk[i] == 2)
			;
		else if (aa[i] == 0 && bb[i] == 1 && kk[i] == 0)
			;
		else if (aa[i] == 0 && bb[i] == 1 && kk[i] == 1)
			return 0LL;
		else if (aa[i] == 0 && bb[i] == 1 && kk[i] == 2)
			;
		else if (aa[i] == 0 && bb[i] == 2 && kk[i] == 0)
			ret *= 2LL;
		else if (aa[i] == 0 && bb[i] == 2 && kk[i] == 1)
			return 0LL;
		else if (aa[i] == 0 && bb[i] == 2 && kk[i] == 2)
			ret *= 2LL;
		else if (aa[i] == 1 && bb[i] == 0 && kk[i] == 0)
			;
		else if (aa[i] == 1 && bb[i] == 0 && kk[i] == 1)
			return 0LL;
		else if (aa[i] == 1 && bb[i] == 0 && kk[i] == 2)
			;
		else if (aa[i] == 1 && bb[i] == 1 && kk[i] == 0)
			return 0LL;
		else if (aa[i] == 1 && bb[i] == 1 && kk[i] == 1)
			;
		else if (aa[i] == 1 && bb[i] == 1 && kk[i] == 2)
			;
		else if (aa[i] == 1 && bb[i] == 2 && kk[i] == 0)
			;
		else if (aa[i] == 1 && bb[i] == 2 && kk[i] == 1)
			;
		else if (aa[i] == 1 && bb[i] == 2 && kk[i] == 2)
			ret *= 2LL;
		else if (aa[i] == 2 && bb[i] == 0 && kk[i] == 0)
			ret *= 2LL;
		else if (aa[i] == 2 && bb[i] == 0 && kk[i] == 1)
			return 0LL;
		else if (aa[i] == 2 && bb[i] == 0 && kk[i] == 2)
			ret *= 2LL;
		else if (aa[i] == 2 && bb[i] == 1 && kk[i] == 0)
			;
		else if (aa[i] == 2 && bb[i] == 1 && kk[i] == 1)
			;
		else if (aa[i] == 2 && bb[i] == 1 && kk[i] == 2)
			ret *= 2LL;
		else if (aa[i] == 2 && bb[i] == 2 && kk[i] == 0)
			ret *= 3LL;
		else if (aa[i] == 2 && bb[i] == 2 && kk[i] == 1)
			;
		else if (aa[i] == 2 && bb[i] == 2 && kk[i] == 2)
			ret *= 4LL;

	return ret;
}

long long check_sub(void) {
	int i;
	long long ret;

	for (i = 0; i < 32; i++)
		kk[i] = 2;

	ret = 0LL;
	for (i = 31; i >= 0; i--)
		if (k >> i & 1) {
			kk[i] = 0;
			ret += check_sub_sub();
			kk[i] = 1;
		} else
			kk[i] = 0;
	ret += check_sub_sub();

	return ret;
}

long long check(void) {
	int i;
	long long ret;

	for (i = 0; i < 32; i++)
		bb[i] = 2;

	ret = 0LL;
	for (i = 31; i >= 0; i--)
		if (b >> i & 1) {
			bb[i] = 0;
			ret += check_sub();
			bb[i] = 1;
		} else
			bb[i] = 0;
	ret += check_sub();

	return ret;
}

int main(void) {
	int i, j, l;
	int t;

	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		long long ans;

		scanf("%d %d %d", &a, &b, &k);
		a--;
		b--;
		k--;

		for (j = 0; j < 32; j++)
			aa[j] = 2;

		ans = 0;
		for (j = 31; j >= 0; j--)
			if (a >> j & 1) {
				aa[j] = 0;
				ans += check();
				aa[j] = 1;
			} else
				aa[j] = 0;
		ans += check();

		printf("Case #%d: %lld\n", i, ans);
	}

	return 0;
}
