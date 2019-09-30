#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#define ll long long
#define endl '\n'
using namespace std;

struct Pos{
  int x;
  int y;
};

int H, W;
vector<string> grid;
bool visited[50][50];
int dx[]{0, 1, 0, -1};
int dy[]{1, 0, -1, 0};

int get_number_of_component(int x, int y)
{
  int ret = 1;
  queue<Pos> quu; quu.push(Pos{x, y}); visited[x][y] = true;

  while(!quu.empty())
    {
      auto cur = quu.front(); quu.pop();
      for(int i = 0; i < 4; i++)
	{
	  auto nx = cur.x + dx[i], ny = cur.y + dy[i];
	  if(min(nx, ny) < 0 || nx >= H || ny >= W) continue;
	  if(visited[nx][ny]) continue;
	  if(grid[nx][ny] == '.') continue;

	  visited[nx][ny] = true;
	  quu.push(Pos{nx, ny});
	  ret += 1;
	}
    }
  return ret;
}

int main(void)
{
  cin.tie(NULL); ios_base::sync_with_stdio(false); cin >> H >> W;
  for(int i = 0; i < H; i++)
    {
      string temp; cin >> temp; grid.push_back(temp);
    }
  for(int i = 0; i < H; i++)
    {
      for(int j = 0; j < W; j++)
	{
	  if(visited[i][j]) continue;
	  if(grid[i][j] == '.') continue;
	  auto ret = get_number_of_component(i, j);
	  if(ret == 1)
	    {
	      cout << "No" << endl;
	      return 0;
	    }
	}
    }


  cout << "Yes" << endl;
  return 0;
}

/*

 */