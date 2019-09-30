#include <stdio.h>
#include <string.h>
int ti, tn, i, n, k, r, cur, pos, q[2500], a[2500], fst[2500];
long long sum[2500];
int main()
{
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		printf("Case #%d: ", ti);
		scanf("%d%d%d", &r, &k, &n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			a[i + n] = a[i];
		}
		memset(fst, 0, sizeof(fst));
		q[0] = 0;
		sum[0] = 0;
		for (cur = 0, pos = 1; !fst[cur]; ++pos) {
			q[++q[0]] = cur;
			fst[cur] = pos;
			for (i = sum[q[0]] = 0; i < n && sum[q[0]] + a[cur + i] <= k; ++i)
				sum[q[0]] += a[cur + i];
			sum[q[0]] += sum[q[0] - 1];
			cur += i;
			if (cur >= n)
				cur -= n;
		}
		if (r < pos)
			printf("%lld\n", sum[r]);
		else {
			r -= fst[cur] - 1;
			printf("%lld\n", sum[fst[cur] - 1] + r / (pos - fst[cur]) * (sum[pos - 1] - sum[fst[cur] - 1]) + sum[fst[cur] + r % (pos - fst[cur]) - 1] - sum[fst[cur] - 1]);
		}
	}
	return 0;
}
