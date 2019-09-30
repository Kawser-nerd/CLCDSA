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
typedef pair<int, int> P;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define amari(x) ((x) % 1000000007)

#define fillInt(xs, x)        \
  for (int i = 0; i < (x); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%ld", &xs[i]);
#define fillString(xs, x)       \
  for (int i = 0; i < (x); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end());
#define sortvdi(xs) sort(xs.begin(), xs.end(), std::greater<int>());
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin();
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin();

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define isValidPoint(x, y, mx, my) x >= 0 && x  < mx && y >= 0 && y < my

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;

  cin >> h >> w;

  char a[h][w];
  vector<string> s(h);

  fillString(s, h);

  rep(i, h) {
    rep(j, w) {
      a[i][j] = s[i][j];
    }
  }

  int x = 0;
  int y = 0;

  while (true) {
    a[y][x] = '.';
    if (x < w-1 && a[y][x+1] == '#') {
      x++;
    } else if (y < h-1 && a[y+1][x] == '#') {
      y++;
    } else {
      break;
    }
  }

  bool res = true;
  rep(i, h) {
    rep(j, w) {
      res = res && (a[i][j] == '.');
    }
  }

  if (res) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }

  return 0;
}