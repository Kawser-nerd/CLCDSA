#include <stdio.h>
#include <math.h>

#define DIS(a, b, c, d) (sqrt((a-c)*(a-c) + (b-d)*(b-d)))

#define MAX 10
#define XDIV 1000
#define YDIV 1000

int main()
{
	int cn, cc;

	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		int n;
		double xm, ym;
		double r[MAX];
		double pos[MAX][2];
		int i, j, k, m;

		scanf("%d%lf%lf", &n, &xm, &ym);
		for (i=0; i<n; i++)
			scanf("%lf", r+i);

		printf("Case #%d:", cc);

		for (i=0; i<n; i++)
		{
			for (j=0; j<=XDIV; j++)
			{
				for (k=0; k<=YDIV; k++)
				{
					double x, y;
					x = xm * ((double)(j)/XDIV);
					y = ym * ((double)(k)/YDIV);

					for (m=0; m<i; m++)
					{
						if (DIS(x, y, pos[m][0], pos[m][1]) < (r[m]+r[i]) * 1.0000001)
							break;
					}

					if (m == i)
					{
						printf(" %f %f", x, y);
						pos[i][0] = x;
						pos[i][1] = y;
						goto NEXT;
					}
				}
			}
NEXT:
			if (j==XDIV+1 && k==YDIV+1)
				fprintf(stderr, "Failed!\n");
		}

		putchar('\n');
	}

	return 0;
}