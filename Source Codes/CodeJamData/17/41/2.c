main()
{
	int itest, ntest;
	scanf("%d", &ntest);
	for (itest = 0; ++itest <= ntest; ) {
		int i, j, k, l, a[128], n, p, res = 0;
		char mark[128];
		scanf("%d%d", &n, &p);
		memset(mark, 0, sizeof(mark));
		for (i = 0; i < n; ++i)
			scanf("%d", a+i);
		for (i = 0; i < n; ++i)
		if (!mark[i] && a[i] % p == 0) {
			mark[i] = 1;
			++res;
		}
		for (i = 0; i < n; ++i)
		for (j = i; ++j < n; )
		if (!mark[i] && !mark[j] &&
		    (a[i] + a[j]) % p == 0) {
			mark[i] = mark[j] = 1;
			++res;
		}
		for (i = 0; i < n; ++i)
		for (j = i; ++j < n; )
		for (k = j; ++k < n; )
		if (!mark[i] && !mark[j] && !mark[k] &&
		    (a[i] + a[j] + a[k]) % p == 0) {
			mark[i] = mark[j] = mark[k] = 1;
			++res;
		}
		for (i = 0; i < n; ++i)
		for (j = i; ++j < n; )
		for (k = j; ++k < n; )
		for (l = k; ++l < n; )
		if (!mark[i] && !mark[j] && !mark[k] && !mark[l] &&
		    (a[i] + a[j] + a[k] + a[l]) % p == 0) {
			mark[i] = mark[j] = mark[k] = mark[l] = 1;
			++res;
		}
		for (i = 0; i < n; ++i)
		if (!mark[i]) {
			++res;
			break;
		}
		printf("Case #%d: %d\n", itest, res);
	}
	return 0;
}
