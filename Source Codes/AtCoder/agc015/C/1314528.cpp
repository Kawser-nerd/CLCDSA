#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include<string>
#include<queue>
 
using namespace std;
 
int dist[2003][2003];
int sum[2003][2003];
int H, W;
 
int vx[]{ 1,0,-1,0 };
int vy[]{ 0,1,0,-1 };
 
bool inside(int y, int x)
{
	return y >= 0 && x >= 0 && y < H && x < W;
}
 
vector<string> board;
 
int main() {
	int Q;
	cin >> H >> W >> Q;
	board = vector<string>(H);
	for (int i = 0; i < H; i++)
	{
		cin >> board[i];
	}
	int MAX = 99999999;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			dist[i][j] = MAX;
		}
	}
 
 
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (board[i][j] == '1')
			{
				if (dist[i][j] != MAX) continue;
				sum[i + 1][j + 1]++;
 
				queue<pair<int, int>> q;
				dist[i][j] = 0;
				q.push(make_pair(i, j));
				while (!q.empty())
				{
					pair<int, int> now = q.front(); q.pop();
					int y = now.first;
					int x = now.second;
					for (int k = 0; k < 4; k++)
					{
						int ny = y + vy[k];
						int nx = x + vx[k];
						if (!inside(ny, nx)) continue;
						if (board[ny][nx] == '0') continue;
						if (dist[ny][nx] != MAX) continue;
 
						//??????????
						dist[ny][nx] = dist[y][x] + 1;
 
						q.push(make_pair(ny, nx));
					}
				}
			}
		}
	}
 
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			sum[i + 1][j + 1] += sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
		}
	}
 
	for (int t = 0; t < Q; t++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		y1--; x1--;
 
		long ans = 0;
		ans += sum[y2][x2] - sum[y1][x2] - sum[y2][x1] + sum[y1][x1];
 
		if (x1 != 0)
		{
			for (int y = y1; y < y2; y++)
			{
				if (dist[y][x1] - 1 == dist[y][x1 - 1]) ans++;
			}
		}
		if (x2 != W)
		{
			for (int y = y1; y < y2; y++)
			{
				if (dist[y][x2 - 1] - 1 == dist[y][x2]) ans++;
			}
		}
 
 
		if (y1 != 0)
		{
			for (int x = x1; x < x2; x++)
			{
				if (dist[y1][x] - 1 == dist[y1 - 1][x]) ans++;
			}
		}
		if (y2 != H)
		{
			for (int x = x1; x < x2; x++)
			{
				if (dist[y2 - 1][x] - 1 == dist[y2][x]) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} ./Main.cpp:126:18: warning: format specifies type 'int' but the argument has type 'long' [-Wformat]
                printf("%d\n", ans);
                        ~~     ^~~
                        %ld
1 warning generated.