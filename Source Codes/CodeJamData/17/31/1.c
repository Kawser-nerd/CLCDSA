cmp(x, y)
int *x, *y; {
	return -(*x < *y ? -1 : *x > *y);
}

llcmp(x, y)
long long *x, *y; {
	return -(*x < *y ? -1 : *x > *y);
}

long long
height(a, n, k)
int (*a)[2]; {
	static long long b[1024];
	int i;
	long long res = 0;
	for (i = 0; i < n; ++i)
		b[i] = a[i][0] * (long long)a[i][1];
	qsort(b, n, sizeof(*b), llcmp);
	for (i = 0; i < k; ++i)
		res += b[i];
	return res;
}

main()
{
	int itest, ntest;
	scanf("%d", &ntest);
	for (itest = 0; ++itest <= ntest; ) {
		int i, n, k, a[1024][2];
		long long res = 0;
		const double pi = 3.14159265358979323846;
		scanf("%d%d", &n, &k);
		for (i = 0; i < n; ++i)
			scanf("%d%d", a[i], a[i]+1);
		qsort(a, n, sizeof(*a), cmp);
		for (i = 0; i < n; ++i) {
			long long t = *a[i] + 2 * a[i][1];
			t *= *a[i];
			t += 2 * height(a + i + 1, n - i - 1, k - 1);
			if (res < t)
				res = t;
		}
		printf("Case #%d: %.6lf\n", itest, pi * res);
	}
	return 0;
}
