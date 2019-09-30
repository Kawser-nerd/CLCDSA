#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int off[4][2] = {{0,1}, {1,0}, {1,1}, {1, -1}};

int main()
{
	int cc,ca;
	cin >> ca;
	for(cc=1;cc<=ca;cc++)
	{
		int i,j,k;
		int N,K;
		cin >> N >> K;
		vector<string> board;
		for(i=0; i<N; i++)
		{
			string line;
			cin >> line;
			string rline;
			for(j=0; j<N; j++)
				rline.push_back('.');
			for(j=line.size()-1,k=0; j>=0; j--)
				if (line[j] != '.')
					rline[k++] = line[j];
			board.push_back(rline);
		}
		int rwin=0, bwin=0;
		for(i=0; i<N; i++) for(j=0; j<N; j++)
		{
			if (board[i][j] == '.') continue;
			for(int dir=0; dir<4; dir++)
			{
				int x = i, y = j, count=1;
				x += off[dir][0]; y += off[dir][1];
				while(x >= 0 && x < N && y >= 0 && y < N && board[x][y] == board[i][j])
				{
					count++;
					if (count >= K) break;
					x += off[dir][0]; y += off[dir][1];
				}
				if (count >= K)
				{
					if (board[i][j] == 'R') rwin=1;
					if (board[i][j] == 'B') bwin=1;
				}
			}
		}
		if (rwin && bwin)
			printf("Case #%d: Both\n", cc);
		else if (rwin)
			printf("Case #%d: Red\n", cc);
		else if (bwin)
			printf("Case #%d: Blue\n", cc);
		else
			printf("Case #%d: Neither\n", cc);
	}
}
