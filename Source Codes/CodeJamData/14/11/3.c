#include <stdio.h>

int main()
{
	int T;
	
	scanf("%d", &T);
	
	for (int Q = 1; Q <= T; Q++)
	{
		int N, L;
		
		scanf("%d %d", &N, &L);
		
		char outlets[N][L+1];
		char devices[N][L+1];
		
		for (int i = 0; i < N; i++)
		{
			scanf(" %s", outlets[i]);
			
//			printf("%s\n", outlets[i]);
		}
		
		for (int i = 0; i < N; i++)
		{
			scanf(" %s", devices[i]);
			
//			printf("%s\n", devices[i]);
		}
		
		int minL = L + 1;
		
		// take first outlet and try to match it against each device
		
		for (int i = 0; i < N; i++)
		{
			int eq[L];
			int currentL = 0;
		
			for (int j = 0; j < L; j++)
			{
				if (outlets[0][j] != devices[i][j])
				{
					eq[j] = 0;
					currentL++;
				}
				else
				{
					eq[j] = 1;
				}
			}
			
			if (currentL >= minL) continue;
			
			// now see that every other outlet matches a device
			
			int allMatch = 1;
			
			for (int k = 1; k < N; k++)
			{
				int someMatch = 0;
			
				for (int l = 0; l < N; l++)
				{
					int thisMatch = 1;
					
					for (int j = 0; j < L; j++)
					{
						if ((outlets[k][j] == devices[l][j]) != eq[j])
						{
							thisMatch = 0;
							break;
						}
					}
					
					if (thisMatch)
					{
						someMatch = 1;
						break;
					}
				}
				
				if (!someMatch)
				{
					allMatch = 0;
					break;
				}
			}
			
			if (allMatch) minL = currentL;
		}
		
		if (minL > L)
		{
			printf("Case #%d: NOT POSSIBLE\n", Q);
		}
		else
		{
			printf("Case #%d: %d\n", Q, minL);
		}
	}
}