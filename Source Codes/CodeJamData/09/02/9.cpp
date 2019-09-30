#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int table[101][101];
vector< int > graph[101][101];
char ret[101][101];
char ch;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void go(int x, int y)
{
	queue<pair<int, int> > Q;
	Q.push( make_pair( x, y ));

	ret[x][y] = ch;
	while (!Q.empty())
	{
		pair<int, int> now = Q.front(); Q.pop();
		
		x = now.first, y = now.second;
		for (int i = 0; i < graph[x][y].size(); ++i)
		{
			int nx = x + dx[ graph[x][y][i] ];
			int ny = y + dy[ graph[x][y][i] ];

			if (ret[nx][ny] == '?') 
			{
				ret[nx][ny] = ch;
				Q.push(make_pair( nx, ny ));
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;

	int n, m;

	for (int q = 1; q <= T; ++q)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				cin >> table[i][j];
				graph[i][j].clear();
				ret[i][j] = '?';
			}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				bool isSink = true;
				int mn = table[i][j];
				int p = -1;

				for (int k = 0; k < 4; ++k)
				{
					int nx = i + dx[k], ny = j + dy[k];
					if (nx < 0 || nx == n || ny < 0 || ny == m) continue;
					if (table[i][j] > table[nx][ny]) isSink = false;
					if (mn > table[nx][ny])
					{
						mn = table[nx][ny];
						p = k;
					}
				}

				if (isSink) continue;

				graph[i][j].push_back( p );
				graph[i + dx[p]][j + dy[p]].push_back( 3 - p );
			}
		}

		ch = 'a';
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if( ret[i][j] == '?' ) 
				{
					go(i, j);
					ch++;
				}
			}
		}
		cout << "Case #" << q << ":" << endl;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				cout << ret[i][j] << ' ';
			cout << endl;
		}
	}
	return 0;
}