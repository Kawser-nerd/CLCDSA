#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>

using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define amari (x) x % 1000000007;

#define fillInt(xs, x)        \
  for (int i = 0; i < x; i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < x; i++) \
    scanf("%ld", &xs[i]);
#define fillString(xs, x)       \
  for (int i = 0; i < x; i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end());
#define sortvdi(xs) sort(xs.begin(), xs.end(), std::greater<int>());
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin();
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin();

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define isValidPoint(x, y, m) x >= 0 && x  < m && y >= 0 && y < m

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

char ys[10][10];

void dfs(int x, int y) {
  ys[x][y] = 'x';
  rep(i, 4)
  {
    int newX = x + dx[i];
    int newY = y + dy[i];
    if (isValidPoint(newX, newY, 10) && ys[newX][newY] == 'o') dfs(newX, newY);
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<string> xs(10);
  fillString(xs, 10);
  
  bool res = false;

  rep(i, 10)
  rep(j, 10)
  {
    ys[i][j] = xs[i][j];
  }

  int a = -1;
  int b = -1;
  rep(i, 10)
  rep(j, 10)
  {
    if (ys[i][j] == 'o') {
      a = i;
      b = j;
    }
  }

  if (a != -1) {
    dfs(a, b);
    bool check = true;
    rep(i, 10)
    rep(j, 10)
    {
      if (ys[i][j] == 'o') check = false;
    }
    res = res || check;
  }


  rep(a, 10)
  rep(b, 10)
  {
    if (xs[a][b] == 'x') {
      rep(i, 10)
      rep(j, 10)
      {
        ys[i][j] = xs[i][j];
      }
      ys[a][b] = 'o';
      dfs(a, b);

      bool check = true;
      rep(i, 10)
      rep(j, 10)
      {
        if (ys[i][j] == 'o') check = false;
      }
      res = res || check;
    }
  } 

  if (res) printf("YES\n"); 
  else printf("NO\n");
  
  return 0;
}