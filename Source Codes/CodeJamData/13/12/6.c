#include <stdio.h>

int arr[10000];
__int64 sum;
int eng, rec;

void Greedy(int beng, int eeng, int bgn, int end);

int main()
{
	int cn, cc;
	freopen("l.in", "r", stdin);
	freopen("l.out", "w", stdout);
	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		int n;
		int i;

		scanf("%d %d %d", &eng, &rec, &n);

		for (i=0; i<n; i++)
			scanf("%d", arr+i);

		sum = 0;
		Greedy(eng, 0, 0, n);
		printf("Case #%d: %I64d\n", cc, sum);
	}

	return 0;
}

// can reach eeng
void Greedy(int beng, int eeng, int bgn, int end)
{
	int maxid;
	int il, ir;
	int t;
	int i;

	for (i=maxid=bgn; i<end; i++){
		if (arr[i] > arr[maxid])
			maxid = i;
	}

	il = beng + rec * (maxid - bgn);
	if (il > eng) il = eng;
	t = rec * (maxid - bgn);
	if (maxid != bgn && t / (maxid - bgn) != rec)
		il = eng;

	ir = eeng - rec * (end - maxid);
	if (ir < 0) ir = 0;
	t = rec * (end - maxid);
	if (end != maxid && t / (end - maxid) != rec)
		ir = 0;

	sum += (__int64)(arr[maxid]) * (__int64)(il - ir);
	if (maxid > bgn)
		Greedy(beng, il, bgn, maxid);
	t = ir + rec;
	if (t > eng) t = eng;
	if (maxid + 1 < end)
		Greedy(t, eeng, maxid + 1, end);
}