#include <stdio.h>

int main (void)
{
	int T, t, N, R, C;
	int total, i, j;

	int e2, e3, e4, esum;
	int o2, o3, o4, osum;

	scanf ("%d", &T);

	for (t = 0; t < T; t++)
	{
		scanf ("%d %d %d", &R, &C, &N);

		total = (R - 1)*C + R*(C - 1);
		N = R*C - N;

		e2 = e3 = e4 = esum =
		o2 = o3 = o4 = osum = 0;

		for (i = 0; i < R; i++)
		{
			for (j = 0; j < C; j++)
			{
				if ((i + j)%2)
				{
					if ((i == 0 && j == 0) || (i == R - 1 && j == C - 1) ||
						(i == 0 && j == C - 1) || (i == R - 1 && j == 0))
						o2++;
					else if (i == 0 || j == 0 || i == R - 1 || j == C - 1)
						o3++;
					else
						o4++;
				}
				else
				{
					if ((i == 0 && j == 0) || (i == R - 1 && j == C - 1) ||
						(i == 0 && j == C - 1) || (i == R - 1 && j == 0))
						e2++;
					else if (i == 0 || j == 0 || i == R - 1 || j == C - 1)
						e3++;
					else
						e4++;
				}
			}
		}

		while (N--)
		{
			if (e4)
			{
				e4--;
				esum += 4;
			}
			else if (e3)
			{
				e3--;
				esum += 3 - (R == 1) - (C == 1);
			}
			else if (e2)
			{
				e2--;
				esum += 2 - (R == 1) - (C == 1);
			}

			if (o4)
			{
				o4--;
				osum += 4;
			}
			else if (o3)
			{
				o3--;
				osum += 3 - (R == 1) - (C == 1);
			}
			else if (o2)
			{
				o2--;
				osum += 2 - (R == 1) - (C == 1);
			}
		}

		printf ("Case #%d: %d\n", t + 1, total - (esum > osum ? esum : osum));
	}
}
