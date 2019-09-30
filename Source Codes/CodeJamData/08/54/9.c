#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;

int mat[101][101];
int W,H;
long long ans[101][101];

int calc(int x, int y)
{
	if (ans[x][y] >= 0) return ans[x][y];
	if (x == 0 && y == 0) return 1;
	if (mat[x][y]) return 0;
	long long& r = ans[x][y];
	r = 0;
	if (x >= 2 && y >= 1)
	{
		r = (r + calc(x-2, y-1)) % 10007;
	}
	if (x >= 1 && y >= 2)
	{
		r = (r + calc(x-1, y-2)) % 10007;
	}
	return r;
}

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		int R;
		cin >> H >> W >> R;
		memset(mat, 0, sizeof(mat));
		for(i=0; i<R; i++)
		{
			int r,c;
			cin >> r >> c;
			mat[r-1][c-1] = 1;
		}
		for(i=0; i<H; i++) for(j=0; j<W; j++)
			ans[i][j] = -1;
		printf("Case #%d: %d\n", cc, calc(H-1, W-1));
	}
}
