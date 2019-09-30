#include <bits/stdc++.h>
using namespace std;

vector < vector <char> > solve(int m, int n, int bomb)
{
	vector < vector <char> > board;
	
	// M = 1
	if (m == 1) 
	{
		// Always possible
		vector <char> row;
		for (int i = 1; i < n; i++) row.push_back(i <= bomb ? '*' : '.');
		row.push_back('c');
		board.push_back(row);
		return board;
	}
	
	int notBomb = m * n - bomb;
	
	// M = 2
	if (m == 2)
	{
		// Impossible
		if (notBomb == 2) return board;
		if (notBomb > 1 && notBomb % 2) return board;
		
		// Possible
		if (notBomb == 1)
		{
			vector <char> row(n, '*');
			for (int i = 0; i < 2; i++) board.push_back(row);
			board[0][0] = 'c';
			return board;
		}
		
		vector <char> row(n, '.');
		for (int i = 0; i < bomb / 2; i++) row[i] = '*';
		for (int i = 0; i < 2; i++) board.push_back(row);
		board[0][n - 1] = 'c';
		return board;
	}
	
	// M > 2
	
	// Impossible
	if (notBomb == 2 || notBomb == 3 || notBomb == 5 || notBomb == 7) return board;
	
	// Possible
	vector <char> row(n, '.');
	for (int i = 0; i < m; i++) board.push_back(row);
	
	// Case 1
	if (notBomb > 2 * m + 1)
	{
		int maxCol = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (j * m + i < bomb)
				{
					board[i][j] = '*';
					maxCol = max(maxCol, j);
				}
		
		if (bomb % m == m - 1) 
		{
			board[m - 2][maxCol] = '.';
			board[0][maxCol + 1] = '*';
		}
		
		board[m - 1][n - 1] = 'c';
		return board;
	}
	
	// Case 2
	if (notBomb % 3 == 0)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (j < 3 && i < notBomb / 3) board[i][j] = '.';
				else board[i][j] = '*';
	}
	
	if (notBomb % 3 == 1)
	{
		if (notBomb == 1)
		{
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++) 	
					board[i][j] = '*';
		}
		else
		{
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (j < 3 && i < (notBomb - 4) / 3) board[i][j] = '.';
					else board[i][j] = '*';
			board[notBomb / 3 - 1][0] = board[notBomb / 3 - 1][1] = '.';
			board[notBomb / 3][0] = board[notBomb / 3][1] = '.';
		}
	}
	
	if (notBomb % 3 == 2)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (j < 3 && i < notBomb / 3) board[i][j] = '.';
				else board[i][j] = '*';
		board[notBomb / 3][0] = board[notBomb / 3][1] = '.';
	}
	
	board[0][0] = 'c';
	return board;
}

int main()
{
	freopen("c-large.in", "r", stdin); 
	freopen("c-large.out", "w", stdout);
	int test;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		int isReversed = 0, m, n, bomb;
		cin >> m >> n >> bomb;
		if (m > n)
		{
			swap(m, n);
			isReversed = 1;
		}
		
		vector < vector <char> > board = solve(m, n, bomb);
		
		printf("Case #%d:\n", noTest);
		if (board.empty()) printf("Impossible\n");
		else 
		{
			if (isReversed)
				for (int i = 0; i < n; i++)	
				{
					for (int j = 0; j < m; j++)
						cout << board[j][i];
					cout << endl;
				}					
			else
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
						cout << board[i][j];
					cout << endl;
				}
		}
	}
}
