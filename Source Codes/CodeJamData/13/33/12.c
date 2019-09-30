#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numCases = 0;

	int i,j,k;

	int N;

	int d[10],n[10],w[10],e[10],s[10],dd[10],dp[10],ds[10];
		
	int success;

	scanf("%d",&numCases);

	for (i=0;i<numCases;i++)
	{	
		int finished = 0;
		int wall[50000] = {0};/* index 25000 is point 0 */
		success = 0;
		scanf("%d",&N);

		for (j=0;j<N;j++)
		{
			scanf("%d",&d[j]);
			scanf("%d",&n[j]);
			scanf("%d",&w[j]);
			scanf("%d",&e[j]);
			scanf("%d",&s[j]);
			scanf("%d",&dd[j]);
			scanf("%d",&dp[j]);
			scanf("%d",&ds[j]);
		}	

		/* simulate day by day until all attacks are done */

		while (!finished)
		{
			/* find min day */
			int mind = 2000000;
			for (j=0;j<N;j++)
			{
				if (n[j]>0 && d[j]<mind)
					mind=d[j];
			}

			/* now perform all the attacks on day mind */

			for (j=0;j<N;j++)
			{
				if (n[j]>0 && d[j]==mind)
				{
					/* check whether the attack is successfull */
					for (k=w[j];k<e[j];k++)
					{
						if (s[j]>wall[25000+k])
						{
							success++;
							break;
						}
					}
				}

			}

			/* now raise the wall that day */
			for (j=0;j<N;j++)
			{
				if (n[j]>0 && d[j]==mind)
				{
					/* check whether the attack is successfull */
					for (k=w[j];k<e[j];k++)
					{
						if (s[j]>wall[25000+k])
						{
							wall[25000+k]=s[j];
						}
					}

					d[j]+=dd[j];
					w[j]+=dp[j];
					e[j]+=dp[j];
					n[j]--;
					s[j]+=ds[j];
				}

			}

			/* now determine whether there are still tribes to attacck */
			finished = 1;
			for (j=0;j<N;j++)
			{
				if (n[j]>0){
					finished = 0;
					break;
				}	
			}
		}
			
		printf("Case #%d: %d\n",i+1,success);
	}

	return 0;
	
}
