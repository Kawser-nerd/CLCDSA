#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	
	for (int t = 1; t <= T; ++t)
	{
		int N;
		scanf("%d", &N);
		
		int J[200], X = 0;
		for (int i = 0; i < N; ++i) scanf("%d", &J[i]), X += J[i];
		
		printf("Case #%d:", t);
		
		double m[200];
		for (int i = 0; i < N; ++i)
		{
			double left = 0, right = 1;
			while (right - left >= 1.0e-10)
			{
				double y = left + (right - left) / 2;
				double votes = 1;
				for (int j = 0; j < N; ++j)
				{
					double yj = (double) (J[i] - J[j]) / X + y;
					if (yj > 0) votes -= yj;
				}
				if (votes > 0) left = y;
				else right = y;
			}
			printf(" %.8f", left * 100 + (right - left) * 50);
		}
		
		putchar('\n');
	}
}
