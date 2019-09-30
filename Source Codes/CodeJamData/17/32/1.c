#define D(i,j)	((a[j][0] + M - a[i][1]) % M)
#define DN(i)	D(i, next[i])
#define S(i)	((next[i] < *n) == (i < *n))

enum{M=24*60};

main()
{
	int itest, ntest;
	scanf("%d", &ntest);
	for (itest = 0; ++itest <= ntest; ) {
		int X, i, j, n[2], nall, r[2], a[1024][2];
		int next[1024], res = 0;
		char mark[1024];
		scanf("%d%d", n, n+1);
		nall = n[0] + n[1];
		printf("Case #%d: ", itest);
		r[0] = r[1] = M / 2;
		for (i = 0; i < nall; ++i) {
			scanf("%d%d", a[i], a[i]+1);
			r[i >= *n] -= (a[i][1] + M - a[i][0]) % M;
			mark[i] = 0;
		}
		if (nall < 2) {
			puts("2");
			continue;
		}
		for (i = 0; i < nall; ++i) {
			int best = 0;
			for (j = 0; j < nall; ++j) {
				if (D(i, j) < D(i, best))
					best = j;
			}
			next[i] = best;
		}
		while (1) {
			int best = -1;
			for (i = 0; i < nall; ++i)
				if (!mark[i] && S(i) && DN(i) <= r[i>=*n]
				    && (best < 0 || DN(i) < DN(best)))
					best = i;
			if (best < 0)
				break;
			mark[best] = 1;
			r[best >= *n] -= DN(best);
		}
		for (i = 0; i < nall; ++i) {
			if (mark[i])
				continue;
			if (S(i))
				res += 2;
			else
				res += 1;
		}
		printf("%d\n", res);
	}
	return 0;
}
