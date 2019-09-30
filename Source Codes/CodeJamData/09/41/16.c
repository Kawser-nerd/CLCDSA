#include <stdio.h>

int main(void)
{
	int T, t;
	char s[64];

	fgets(s, 64, stdin);
	sscanf(s, "%d\n", &T);

	for(t = 1; t <= T; ++t)
	{
		int N, i, S = 0;
		char M[40];

		fgets(s, 64, stdin);
		sscanf(s, "%d\n", &N);

		for(i = 0; i < N; ++i)
		{
			int j;

			fgets(s, 64, stdin);

			M[i] = 0;
			for(j = 0; j < N; ++j)
			{
				if(s[j] == '1')
					M[i] = j;
			}
		}
		for(i = 0; i < N; ++i)
		{
			int j, k, t;

			for(j = i; j < N; ++j)
			{
				if(M[j] <= i)
					break;
			}

			S += j - i;

			t = M[j];

			for(k = j; k > i; --k)
			{
				M[k] = M[k-1];
			}

			M[i] = t;
		}
		printf("Case #%d: %d\n", t, S);
	}

	return 0;
}
