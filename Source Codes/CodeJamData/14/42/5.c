#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++)
	{
		int N;
		scanf("%d", &N);
		int A[N];
		for (int i=0; i<N; i++)
			scanf("%d", &A[i]);
		int L = 0;
		int R = N-1;
		int cost = 0;
		for (int s=0; s<N; s++)
		{
			int m = L;
			for (int i=L; i<=R; i++)
				if (A[i] < A[m])
					m = i;
			if (m - L < R - m)
			{
				cost += m-L;
				for (int i=m; i>L; i--)
					A[i] = A[i-1];
				L++;
			}
			else
			{
				cost += R-m;
				for (int i=m; i<R; i++)
					A[i] = A[i+1];
				R--;
			}
		}
		printf("Case #%d: %d\n", t, cost);
	}
	return 0;
}
