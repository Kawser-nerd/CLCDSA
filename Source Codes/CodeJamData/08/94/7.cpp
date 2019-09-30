#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <numeric>
#include <complex>

using namespace std;

const int INF = 1<<30;

int X, Y;
vector <string> grid;
int plen[2][100][100];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void flood(int x, int y, int k) {
  queue < pair <int, int> > q;
  plen[k][x][y] = 0;
  q.push(make_pair(x, y));
  while (!q.empty()) {
    x = q.front().first, y = q.front().second; q.pop();
    for (int l = 0; l < 4; l++) {
      int nx = x+dx[l], ny = y+dy[l];
      if (0 <= nx && nx < X && 0 <= ny && ny < Y && grid[nx][ny] != '.' &&
	  plen[k][nx][ny] == INF) {
	plen[k][nx][ny] = plen[k][x][y]+1;
	q.push(make_pair(nx, ny));
      }
    }
  }
}

int main(void)
{
  int NUM_CASES;
  cin >> NUM_CASES;
  for (int c = 1; c <= NUM_CASES; c++) {
    cin >> X >> Y;
    grid.clear(); grid.resize(X);
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < X; i++)
	for (int j = 0; j < Y; j++)
	  plen[k][i][j] = INF;
    int x = -1, y = -1;
    for (int i = 0; i < X; i++) {
      cin >> grid[i];
      for (int j = 0; j < Y; j++)
	if (grid[i][j] == 'T' && i+j > 0) {
	  x = i; y = j;
	}
    }
    flood(0, 0, 0);
    /*
    for (int i = 0; i < X; i++) {
      for (int j = 0; j < Y; j++)
	cerr << plen[0][i][j] << " ";
      cerr << endl;
    }
    */
    int ans = 0;
    if (x != -1) {
      for (int d = plen[0][x][y]; d > 0; d -= 2)
	ans += d;
      flood(x, y, 1);
      /*
    for (int i = 0; i < X; i++) {
      for (int j = 0; j < Y; j++)
	cerr << plen[1][i][j] << " ";
      cerr << endl;
    }
      */
    }
    for (int i = 0; i < X; i++)
      for (int j = 0; j < Y; j++)
	if (grid[i][j] != '.')
	  ans += min(plen[0][i][j], plen[1][i][j]);
    printf("Case #%d: %d\n", c, ans);
  }
}
