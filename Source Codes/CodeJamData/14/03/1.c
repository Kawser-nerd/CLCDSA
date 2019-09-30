#include <stdio.h>

int main()
{
	int T;
	
	scanf("%d", &T);
	
	for (int Q = 1; Q <= T; Q++)
	{
		int R, C, M, good, flipped = 0;
		
		scanf("%d %d %d", &R, &C, &M);
		
//		printf("$$ %d %d %d (%d)\n", R, C, M, R * C - M);
		
		// normalize so R = min(R, C)
		
		if (C < R)
		{
			flipped = C;
			C = R;
			R = flipped;
		}
		
		M = R * C - M; // easier to think about empty cells
		
		char b[R][C];
		
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				b[i][j] = '*';
			}
		}
		
		if (M == 1)
		{
			good = 1;
			
			b[0][0] = 'c';
		}
		else if (R == 1)
		{
			good = 1;
			
			// fill row in from the beginning
			
			b[0][0] = 'c';
			
			for (int i = 1; i < M; i++)
			{
				b[0][i] = '.';
			}
			
		}
		else if (M == 2)
		{
			good = 0;
		}
		else if (R == 2)
		{
			good = !(M % 2);
			
			b[0][0] = 'c';
			b[1][0] = '.';
			
			if (good)
			{
				for (int i = 1; i < M / 2; i++)
				{
					b[0][i] = b[1][i] = '.';
				}
			}
		}
		else if (M == 3 || M == 5 || M == 7)
		{
			good = 0;
		}
		else if (M < 3 * C)
		{
			int cols = (M - 2) / 3;
				
			for (int i = 0; i < cols; i++)
			{
				b[0][i] = b[1][i] = b[2][i] = '.';
			}
				
			switch (M % 3)
			{
				case 0:
					b[0][cols] = b[1][cols] = b[2][cols] = '.';
					break;
			
				case 1:
					b[0][cols] = b[1][cols] = b[0][cols + 1] = b[1][cols + 1] = '.';
					break;
					
				case 2:
					b[0][cols] = b[1][cols] = '.';
					break;
			}
			
			b[0][0] = 'c';
			
			good = 1;
		}
		else
		{
			int off = M / C - 1;
				
			for (int i = 0; i < off; i++)
			{
				for (int j = 0; j < C; j++)
				{
					b[i][j] = '.';
				}
			}
			
			M -= off * C;
			
			// R >= C >= 4
			// C <= M < 2 * C
			// R >= off + 2
			
			if (M == 3)
			{
				b[off][0] = b[off][1] = b[off][2] = '.';
			}
			else
			{
				for (int i = 0; i < M / 2; i++)
				{
					b[off][i] = b[off + 1][i] = '.';
				}
				
				if (M % 2)
				{
					b[off][M / 2] = '.';
				}
			}
			
			b[0][0] = 'c';
			
			good = 1;
		}
		
		if (good)
		{
			printf("Case #%d:\n", Q);
			
			if (flipped)
			{
				for (int j = 0; j < C; j++)
				{
					for (int i = 0; i < R; i++)
					{
						putchar(b[i][j]);
					}
					
					putchar('\n');
				}
			}
			else
			{
				for (int i = 0; i < R; i++)
				{
					for (int j = 0; j < C; j++)
					{
						putchar(b[i][j]);
					}
					
					putchar('\n');
				}
			}
		}
		else
		{
			printf("Case #%d:\nImpossible\n", Q);
		}
	}
}