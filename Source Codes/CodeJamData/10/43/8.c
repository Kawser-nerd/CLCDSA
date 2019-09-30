#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int board[2][101][101];

int main()
{
	int i,j,k,h,w;
	int cc,ca;
	cin >> ca;
	for(cc=1;cc<=ca;cc++)
	{
		int R;
		cin >> R;
		memset(board, 0, sizeof(board));
		h = 0, w = 0;
		for(i=0; i<R; i++)
		{
			int x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			for(j=x1-1; j<=x2-1; j++) for(k=y1-1; k<=y2-1; k++)
				board[0][j][k] = 1;
		}
		int t = 0, flag = 0, p = 0;
		while(1)
		{
/*			cout << t << endl;
			for(i=0; i<10; i++)
			{
				for(j=0; j<10; j++)
					cout << board[p][i][j] << ' ';
				cout << endl;
			}
*/
			flag = 0;
			for(i=0; i<100; i++) for(j=0; j<100; j++) board[!p][i][j] = 0;
			for(i=0; i<100; i++) for(j=0; j<100; j++)
			{
				if (board[p][i][j])
				{
					if ((i == 0 || board[p][i-1][j] == 0) && (j == 0 || board[p][i][j-1] == 0))
						board[!p][i][j] = 0;
					else
					{
						board[!p][i][j] ++;
						flag = 1;
					}
				}
				else
				{
					if (i > 0 && board[p][i-1][j] != 0 && j > 0 && board[p][i][j-1] != 0)
					{
						board[!p][i][j] ++;
						flag = 1;
					}
				}
			}
			t++; p = !p;
			if (flag == 0) break;
		}
		printf("Case #%d: %d\n", cc, t);
	}
}
