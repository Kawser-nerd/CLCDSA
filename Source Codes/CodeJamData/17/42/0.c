n, a[1024];
solve(p)
{
	int i, sum = 0, res = 0;
	for (i = 0; i < n; ++i) {
		if (p < a[i])
			res += a[i] - p;
		sum += p - a[i];
		if (sum < 0)
			return -1;
	}
	return res;
}

main()
{
	int itest, ntest;
	scanf("%d", &ntest);
	for (itest = 0; ++itest <= ntest; ) {
		int i, np, nb, low = 0, high;
		int pc[1024];
		memset(a, 0, sizeof(a));
		memset(pc, 0, sizeof(pc));
		scanf("%d%d%d", &n, &np, &nb);
		for (i = 0; i < nb; ++i) {
			int j, id;
			scanf("%d%d", &j, &id);
			++a[--j];
			++pc[--id];
			if (low < pc[id])
				low = pc[id];
		}
		high = nb;
		while (low < high) {
			int mid = low + high >> 1;
			if (solve(mid) < 0)
				low = mid + 1;
			else
				high = mid;
		}
		printf("Case #%d: %d %d\n", itest, low, solve(low));
	}
	return 0;
}
