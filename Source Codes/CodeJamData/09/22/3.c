#include <stdio.h>
#include <string.h>

int qcmp(const char * a, const char * b)
{
	if(*a < *b)
		return -1;
	if(*a > *b)
		return 1;
	return 0;
}

int main(void)
{
	int T, t;
	char s[32];

	fgets(s, 32, stdin);
	sscanf(s, "%d", &T);

	for(t = 1; t <= T; ++t)
	{
		char N[32];
		int i, n;

		fgets(s, 32, stdin);
		sscanf(s, "%s", N);
		n = strlen(N);
		for(i = n-1; i > 0; --i)
		{
			if(N[i] > N[i-1])
				break;
		}
		printf("Case #%d: ", t);
		if(i > 0)
		{
			char c = N[i];
			int j, k;
			k = i;
			for(j = i + 1; j < n; ++j)
			{
				if( (N[j] < c) && (N[j] > N[i-1]) )
				{
					c = N[j];
					k = j;
				}
			}
			c = N[i-1];
			N[i-1] = N[k];
			N[k] = c;
			qsort(N + i, n - i, sizeof(char), qcmp);
			for(i = 0; i < n; ++i)
				printf("%c", N[i]);
			printf("\n");
		}
		else
		{
			N[n++] = '0';
			qsort(N, n, sizeof(char), qcmp);

			for(i = 0; i < n; ++i)
			{
				if(N[i] != '0')
					break;
			}

			N[0] = N[i];
			N[i] = '0';
			for(i = 0; i < n; ++i)
				printf("%c", N[i]);
			printf("\n");
		}
	}

	return 0;
}
