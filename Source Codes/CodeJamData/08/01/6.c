#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findEngine(char**, int, char*);

int main(void)
{
	int i, j;
	int sum;

	int N, S, Q; // test cases, search engines, queries
	char **sS;
	char sQuery[101];
	int *sQ, *sOn;
	int switches;



	scanf("%d", &N);
	for (i = 0; i < N; ++i)
	{
		switches = 0;

		// memory allocations and initialization
		scanf("%d%*c", &S);
		sS = malloc(S * sizeof(char*));
		sOn = malloc(S * sizeof(int));
		memset(sOn, 0, S * sizeof(int));
		for (j = 0; j < S; ++j)
		{
			sS[j] = malloc(101 * sizeof(char));
			scanf("%[^\n]%*c", sS[j]);
		}
		scanf("%d%*c", &Q);
		sQ = malloc(Q * sizeof(int));
		for (j = 0; j < Q; ++j)
		{
			scanf("%[^\n]%*c", sQuery);
			sQ[j] = findEngine(sS, S, sQuery);
		}

		// process queries
		sum = 0;
		for (j = 0; j < Q; ++j)
		{
			if (sOn[sQ[j]] == 1)
			{
				// continue;
				// do nothing
			}
			else
			{
				if (sum == S - 1) // time to switch engine
				{
					++switches;
					memset(sOn, 0, S * sizeof(int));
					sOn[sQ[j]] = 1;
					sum = 1;
				}
				else
				{
					sOn[sQ[j]] = 1;
					++sum;
				}
			}
		}
		printf("Case #%d: %d\n", i + 1, switches);


		// free
		for (j = 0; j < S; ++j)
		{
			free(sS[j]);
		}
		free(sS); free(sOn); free(sQ);
	}
	return 0; 
}

int findEngine(char** sS, int S, char* sQuery)
{
	int j;

	for (j = 0; j < S; ++j)
	{
		if (strcmp(sS[j], sQuery) == 0)
			return j;
	} 

	return -1;
}
