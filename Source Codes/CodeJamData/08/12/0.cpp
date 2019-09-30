#include <stdlib.h>
#include <stdio.h>

bool canUse[2100][2100];
int numCase, numFlavor, numCustomer;
int malted[2100];
int numCanUse[2100];
bool choice[2100];
bool visited[2100];

int main()
{
	scanf("%d", &numCase);
	int i, j, k, nl, c1, c2;
	for (i = 0; i < numCase; i++)
	{
		scanf("%d %d", &numFlavor, &numCustomer);
		for (j = 0; j < numCustomer; j++)
			for (k = 0; k < numFlavor; k++)
				canUse[j][k] = false;
		for (j = 0; j < numCustomer; j++)
		{
			malted[j] = -1;
			numCanUse[j] = 0;
			visited[j] = false;
		}

		for (j = 0; j < numCustomer; j++)
		{
			scanf("%d", &nl);
			for (k = 0; k < nl; k++)
			{
				scanf("%d %d", &c1, &c2);
				c1--;
				if (c2 == 1)
					malted[j] = c1;
				else
				{
					canUse[j][c1] = true;
					numCanUse[j]++;
				}
			}
		}

		for (j = 0; j < numFlavor; j++)
			choice[j] = false;

		bool possible = true;
		while (true)
		{
			bool found = false;
			for (j = 0; j < numCustomer; j++)
			{
				if (numCanUse[j] == 0 && !visited[j])
				{
					visited[j] = true;
					found = true;
					if (malted[j] == -1)
					{
						possible = false;
						break;
					}
					else
					{
						choice[malted[j]] = true;
						for (k = 0; k < numCustomer; k++)
						{
							if (canUse[k][malted[j]] == true)
							{
								numCanUse[k]--;
								canUse[k][malted[j]] = false;
							}
						}
					}
				}
			}
			if (!found)
				break;
			if (!possible)
				break;
		}
		printf("Case #%d:", i+1);
		if (possible)
		{
			for (j = 0; j < numFlavor; j++)
			{
				if (choice[j])
					printf(" 1");
				else
					printf(" 0");
			}
		}
		else
		{
			printf(" IMPOSSIBLE");
		}
		printf("\n");
	}
	return 0;
}
