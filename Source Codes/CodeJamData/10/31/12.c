/* A */

#include <stdio.h>

int wires[1005][2];

main ()
{
	int T, t=0, N, i, k, res;

	scanf("%d", &T);

	while (t++<T)
	{
		scanf("%d", &N);

		for (i=0; i<N; ++i)
			scanf("%d%d", &wires[i][0], &wires[i][1]);

		res = 0;

		for (i=0; i<N; ++i)
			for (k=i+1; k<N; ++k)
				if (wires[i][0] < wires[k][0])
				{
					if (wires[i][1] > wires[k][1])
						++res;
				}
				else
				{
					if (wires[i][1] < wires[k][1])
						++res;
				}
		printf("Case #%d: %d\n", t, res);
	}

	return 0;
}

