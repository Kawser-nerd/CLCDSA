#include <stdio.h>
 
int G[200][200];
int d[] = {0, 0, 1, -1};
int e[] = {1, -1, 0, 0};

int main()
{
    FILE *input, *output;
    int a, i, j, k, x, y, b;
    int N, R, C, A;
    char c;
     
    input = fopen("pegman.in", "r");
    output = fopen("pegman.out", "w");
     
    fscanf(input, "%d\n",&N);
     
    for(a=0; a<N; a++)
    {
        fscanf(input, "%d %d\n", &R, &C);
         
        for(i=0; i<R; i++)
        {
			for(j=0; j<C; j++)
			{
				fscanf(input, "%c", &c);
				if(c == '^')
					G[i][j] = 1;
				if(c == 'v')
					G[i][j] = 0;
				if(c == '>')
					G[i][j] = 2;
				if(c == '<')
					G[i][j] = 3;
				if(c == '.')
					G[i][j] = 4;
			}
			fscanf(input, "\n");
        }
		
		for(i=0, A=0; i<R; i++)
		{
			for(j=0; j<C; j++)
			{
				if(G[i][j] == 4)
					continue;
				x = i+e[G[i][j]];
				y = j+d[G[i][j]];
				while(x < R && x >= 0 && y < C && y >= 0)
				{
					if(G[x][y] != 4)
						break;
						
					x += e[G[i][j]];
					y += d[G[i][j]];
				}
				
				if(x < R && x >= 0 && y < C && y >= 0)
					continue;
				
				b = 0;
				for(k=0; k<R; k++)
				{
					if(G[k][j] != 4 && k != i)
					{
						b = 1;
					}
				}
				for(k=0; k<C; k++)
				{
					if(G[i][k] != 4 && k != j)
					{
						b = 1;
					}
				}
				
				if(b == 1)
					A++;
				else
				{
					A = -1;
					break;
				}
			}
			
			if(A == -1)
				break;
		}
        
		if(A != -1)
			fprintf(output, "Case #%d: %d\n", (a+1), A);
		else
			fprintf(output, "Case #%d: IMPOSSIBLE\n", (a+1));
    }
     
    return 0;
}