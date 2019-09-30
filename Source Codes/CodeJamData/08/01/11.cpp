#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int numSwitch[1001];
char engineNames[101][110];
int query[1001];
char strQuery[110];
int numEngine, numQuery;
bool used[101];

int main()
{
	int numCase;
	scanf("%d", &numCase);
	int i, j, k;
	for (i = 0; i < numCase; i++)
	{
		scanf("%d\n", &numEngine);
		for (j = 0; j < numEngine; j++)
		{
			gets(engineNames[j]);
		}
		scanf("%d\n", &numQuery);
		if (numQuery == 0)
		{
			printf("Case #%d: 0\n", i+1);
			continue;
		}
		for (j = 0; j < numQuery; j++)
		{
			gets(strQuery);
			query[j] = -1;
			for (k = 0; k < numEngine; k++)
				if (strcmp(strQuery, engineNames[k]) == 0)
					query[j] = k;
			assert(query[j] != -1);
		}
		numSwitch[0] = 0;
		for (j = 1; j <= numQuery; j++)
			numSwitch[j] = -1;
		for (j = 0; j < numQuery; j++)
		{
			if (numSwitch[j] == -1) continue;

			for (k = 0; k < numEngine; k++)
				used[k] = false;
			int numUsed = 0;
			int lastChanged = -1;
			for (k = j; k < numQuery; k++)
			{
				if (used[query[k]] == false)
				{
					used[query[k]] = true;
					numUsed++;
					lastChanged = query[k];
				}
				if (numUsed == numEngine)
					break;
			}
			if (k == numQuery)
			{
				printf("Case #%d: %d\n", i+1, numSwitch[j]);
				break;
			}
			else
			{
				if (numSwitch[k] == -1 || numSwitch[k] > numSwitch[j]+1)
					numSwitch[k] = numSwitch[j]+1;
			}
		}
	}
	return 0;
}
