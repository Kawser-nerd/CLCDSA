#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(a,b)	(((a) < (b)) ? (a) : (b))
#define MAX(a,b)	(((a) > (b)) ? (a) : (b))

#define INFINITO	0x3F3F3F3F

#define DIST(a,b)	(((a) * (a)) + ((b) * (b)))

#define EPS		1e-6

int main (void)
{
	int	nc,
		h;
	int	n,
		m;
	int	o;
	int	x1,
		y1;
	int	x2,
		y2;
	int	x3,
		y3;
	double	a,
		b,
		c;
	double	p;
	double	s;

	for (scanf("%d", &nc), h = 1; h <= nc; h++)
	{
		scanf("%d%d%d", &n, &m, &o);
		x1 = y1 = 0;
		for (x2 = 0; x2 <= n; x2++)
		{
			for (y2 = 0; y2 <= m; y2++)
			{
				for (x3 = 0; x3 <= n; x3++)
				{
					for (y3 = 0; y3 <= m; y3++)
					{
						a = sqrt(DIST(x1 - x2, y1 - y2));
						b = sqrt(DIST(x2 - x3, y2 - y3));
						c = sqrt(DIST(x3 - x1, y3 - y1));
						p = (a + b + c) / 2;
						s = p * (p - a) * (p - b) * (p - c);
						if (fabs((4 * s) - (o * o)) <= EPS)
						{
							break;
						}
					}
					if (y3 <= m)
					{
						break;
					}
				}
				if (x3 <= n)
				{
					break;
				}
			}
			if (y2 <= m)
			{
				break;
			}
		}
		printf("Case #%d: ", h);
		if (x2 <= n)
		{
			printf("%d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3);
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}

	return 0;
}
