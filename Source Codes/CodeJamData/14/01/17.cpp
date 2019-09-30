#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout);
	int test;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		int row1, row2, board1[5][5], board2[5][5];
		
		cin >> row1;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				cin >> board1[i][j];
				
		cin >> row2;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				cin >> board2[i][j];
				
		set <int> possibleCards;
		for (int j = 1; j <= 4; j++)
			for (int jj = 1; jj <= 4; jj++)
				if (board1[row1][j] == board2[row2][jj])
					possibleCards.insert(board1[row1][j]);
		
		printf("Case #%d: ", noTest);
		if (possibleCards.empty()) printf("Volunteer cheated!\n");
		else
			if (possibleCards.size() > 1) printf("Bad magician!\n");
			else printf("%d\n", *possibleCards.begin());
	}
}
