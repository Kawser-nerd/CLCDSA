#include <stdio.h>

int main()
{
	int T, poss[4], row, dump, res;

	scanf("%d", &T);
	
	for (int Q = 1; Q <= T; Q++)
	{
		scanf("%d", &row);
		
		// first grid -- only copy out the row that was guessed!
		
		for (int i = 4; i < row * 4; i++)
		{
			scanf("%d", &dump);
		}
		
		for (int i = 0; i < 4; i++)
		{
			scanf("%d", &poss[i]);
		}
		
		for (int i = (row + 1) * 4; i < 20; i++)
		{
			scanf("%d", &dump);
		}
		
		// second grid -- flag all things that are in that row
		
		scanf("%d", &row);
		
		for (int i = 4; i < row * 4; i++)
		{
			scanf("%d", &dump);
		}
		
		res = 0;

		for (int i = 0; i < 4; i++)
		{
			scanf("%d", &dump);
		
			for (int j = 0; j < 4; j++)
			{
				if (poss[j] == dump)
				{
					if (res)
					{
						res = -1;
					}
					else
					{
						res = dump;
					}
				}
			}
		}
		
		for (int i = (row + 1) * 4; i < 20; i++)
		{
			scanf("%d", &dump);
		}
		
		if (res == -1)
		{
			printf("Case #%d: Bad magician!\n", Q);
		}
		else if (res)
		{
			printf("Case #%d: %d\n", Q, res);
		}
		else
		{
			printf("Case #%d: Volunteer cheated!\n", Q);
		}
	}
}