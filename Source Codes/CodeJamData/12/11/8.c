#include <stdio.h>

int main()
{
	int cn, cc;

	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		int i;
		int tlen, len;
		double p[100000];
		double crp;
		double minex;

		scanf("%d%d", &tlen, &len);
		for (i=0; i<tlen; i++)
			scanf("%lf", p+i);

		minex = len + 2;

		crp = 1.0;
		for (i=1; i<=tlen; i++)
		{
			double tex;
			crp *= p[i-1];
			tex = tlen - i + len - i + 1 + (1.0 - crp) * (len + 1);
			if (tex < minex)
				minex = tex;
		}

		printf("Case #%d: %.6f\n", cc, minex);
	}

	return 0;
}