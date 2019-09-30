main()
{
	int itest, ntest;
	scanf("%d", &ntest);
	for (itest = 0; ++itest <= ntest; ) {
		int i, n, k;
		double l, h, u, a[1024], res = 1;
		scanf("%d%d%lf", &n, &k, &u);
		for (i = 0; i < n; ++i)
			scanf("%lf", a+i);
		for (l = i = 0, h = 1; i < 100; ++i) {
			double m = 0.5 * (l + h);
			double s = 0;
			int j;
			for (j = 0; j < n; ++j)
			if (a[j] < m)
				s += m - a[j];
			if (s < u)
				l = m;
			else
				h = m;
		}
		l = 0.5 * (l + h);
		for (i = 0; i < n; ++i)
			res *= a[i] < l ? l : a[i];
		printf("Case #%d: %.6lf\n", itest, res);
	}
	return 0;
}
