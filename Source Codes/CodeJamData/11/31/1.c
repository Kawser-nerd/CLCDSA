#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>
using namespace std;


char mat[100][100];
int R,C;

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		memset(mat, 0, sizeof(mat));

		cin >> R >> C;
		for(i=0; i<R; i++)
		{
			string row;
			cin >> row;
			for(j=0; j<C; j++)
				mat[i][j] = row[j];
		}

		int flag = 0;
		int valid = 1;
		do{
			flag = 0;
			for(i=0; i<R; i++) 
			{
				for(j=0; j<C; j++)
				{
					if (mat[i][j] != '#') continue;
					if (j == C-1 || i == R-1)
					{
						valid = 0;
						break;
					}
					if (!(mat[i][j+1] == '#' && mat[i+1][j] == '#' && mat[i+1][j+1] == '#'))
					{
						valid = 0;
						break;
					}
					flag = 1;
					mat[i][j] = '/'; mat[i][j+1] = '\\';
					mat[i+1][j] = '\\'; mat[i+1][j+1] = '/';
				}
				if (!valid)
					break;
			}
			if (!valid)
				break;
		}while(flag);

		for(i=0; i<R; i++) for(j=0; j<C; j++)
			if (mat[i][j] == '#')
			{
				valid = 0;
				break;
			}
		printf("Case #%d:\n", cc);
		if (!valid)
		{
			printf("Impossible\n");
		}
		else
		{
			for(i=0; i<R; i++)
			{
				for(j=0; j<C; j++)
					printf("%c", mat[i][j]);
				printf("\n");
			}
		}
	}	
}
