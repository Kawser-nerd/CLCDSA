#include <stdio.h>

int orig[51][51];
int newdiam[154][154];

int main()
{
	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; c++)
	{
		int k;
		scanf("%d", &k);
		for (int i=0; i<k; i++)
			for (int j=0; j<=i; j++)
				scanf("%d", &orig[i-j][j]);
		for (int i=k; i<2*k-1; i++)
			for (int j=i-(k-1); j <= k-1; j++)
				scanf("%d", &orig[i-j][j]);

		int kk;
		for (kk=k; kk <= 3*k; kk++)
		{
			for (int i=0; i<=kk-k; i++)
				for (int j=0; j<=kk-k; j++)
				{
					memset(newdiam, -1, sizeof(newdiam));
					for (int a=0; a<k; a++)
						for (int b=0; b<k; b++)
							newdiam[i+a][j+b] = orig[a][b];
					
					for (int bla=1; bla < 4; bla++)
					{
						for (int a=0; a<kk; a++)
							for (int b=0; b<kk; b++)
								if (newdiam[a][b] == -1)
								{
									newdiam[a][b] = newdiam[kk-1-b][kk-1-a];
								}
								else if (newdiam[kk-1-b][kk-1-a] == -1)
								{
									newdiam[kk-1-b][kk-1-a] = newdiam[a][b];
								}
								else if (newdiam[a][b] != newdiam[kk-1-b][kk-1-a])
									goto bad;

						for (int a=0; a<kk; a++)
							for (int b=0; b<kk; b++)
								if (newdiam[a][b] == -1)
								{
									newdiam[a][b] = newdiam[b][a];
								}
								else if (newdiam[b][a] == -1)
								{
									newdiam[b][a] = newdiam[a][b];
								}
								else if (newdiam[a][b] != newdiam[b][a])
									goto bad;
					}
					goto found;
bad:			;
				}
		}
found:
		printf("Case #%d: %d\n", c, kk*kk-k*k);
	}
}
