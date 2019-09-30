#include<stdio.h>
int main() {
	int A, B, C, D, E, F;
	scanf("%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F);
	//A = 1, B = 2, F = 200;
	//C = 10, D = 20, E = 15;

	int a, b, c, d, x, y;
	double noudo = 0, noudomax = 0, noudolim = 0;
	int ansa = 0, ansb = 0;

	noudolim = (double)E / (100 + (double)E);
	for (a = 0; a <= F / (100 * A); a++)
	{
		for (b = 0; b <= F / (100 * B); b++)
		{
			for (c = 0; c <= F / C; c++)
			{
				for (d = 0; d <= F / D; d++)
				{
					x = 100 * A * a + 100 * B * b;
					y = C * c + D * d;
					if (x > 0)
					{
						if (x + y <= F)
						{
							noudo = (double)y / ((double)x + (double)y);
							if (noudo <= noudolim)
							{
								//printf("a:%d b:%d c:%d d:%d \n", a, b, c, d);
								//printf("noudo:%lf \n", noudo);
								//printf("noudomax:%lf \n", noudomax);
								if (noudo > noudomax && x != 0)
								{
									noudomax = noudo;
									ansa = x + y;
									ansb = y;
									//printf("a:%d b:%d c:%d d:%d \n", a, b, c, d);
									//printf("noudo:%lf \n", noudo);
									//printf("noudomax:%lf \n", noudomax);
									//printf("%d %d\n", x + y, y);
								}
								//printf("\n");
							}
						}
					}
				}
			}
		}
	}
	if (noudomax == 0)
	{
		ansa = 100*A;
	}
	printf("%d %d\n", ansa, ansb);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F);
  ^