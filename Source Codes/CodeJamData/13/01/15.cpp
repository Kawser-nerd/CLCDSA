#include <cstdio>

using namespace std;

void doCase()
{
	char board[4][4];
	
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			scanf(" %c", &board[i][j]);
		}
	}
	
	// rows
	for (int i=0; i<4; i++)
	{
		int nO = 0;
		int nX = 0;
		for (int j=0; j<4; j++)
		{
			if (board[i][j] == 'X')
				nX++;
			if (board[i][j] == 'O')
				nO++;
			if (board[i][j] == 'T')
			{
				nX++;
				nO++;
			}
		}
		if (nO == 4)
		{
			printf("O won\n");
			return;
		}
		if (nX == 4)
		{
			printf("X won\n");
			return;
		}
	}
	
	// columns
	for (int i=0; i<4; i++)
	{
		int nO = 0;
		int nX = 0;
		for (int j=0; j<4; j++)
		{
			if (board[j][i] == 'X')
				nX++;
			if (board[j][i] == 'O')
				nO++;
			if (board[j][i] == 'T')
			{
				nX++;
				nO++;
			}
		}
		if (nO == 4)
		{
			printf("O won\n");
			return;
		}
		if (nX == 4)
		{
			printf("X won\n");
			return;
		}
	}
	
	int nO = 0, nX = 0;
	// diagonals
	for (int i=0; i<4; i++)
	{
		if (board[i][i] == 'O')
			nO++;
		if (board[i][i] == 'X')
			nX++;
		if (board[i][i] == 'T')
		{
			nO++;
			nX++;
		}
	}
	if (nO == 4)
	{
		printf("O won\n");
		return;
	}
	if (nX == 4)
	{
		printf("X won\n");
		return;
	}
	
	nO = nX = 0;
	for (int i=0; i<4; i++)
	{
		if (board[i][3-i] == 'O')
			nO++;
		if (board[i][3-i] == 'X')
			nX++;
		if (board[i][3-i] == 'T')
		{
			nO++;
			nX++;
		}
	}
	if (nO == 4)
	{
		printf("O won\n");
		return;
	}
	if (nX == 4)
	{
		printf("X won\n");
		return;
	}
	
	// check draw
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			if (board[i][j] == '.')
			{
				printf("Game has not completed\n");
				return;
			}
		}
	}
	
	printf("Draw\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	
	for (int i=1; i<=T; i++)
	{
		printf("Case #%d: ", i);
		doCase();
	}
	
	return 0;
}
