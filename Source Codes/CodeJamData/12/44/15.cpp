#include <cassert>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

char a[105][105];
int ans[105], anscnt[105];

int markmove[65][65];
int num;

vector <pii> move (const vector <pii> &v, int dx, int dy) {
  num++;
  vector <pii> res;
  for (int i = 0; i < (int)v.size(); i++) {
    int nx = v[i].first + dx;
    int ny = v[i].second + dy;
    if (a[nx][ny] == '#') {
      nx = v[i].first;
      ny = v[i].second;
    }
    if (markmove[nx][ny] != num) {
      markmove[nx][ny] = num;
      res.push_back (make_pair (nx, ny));
    }
  }
  return res;
}

char mark[65][65];
vector <pii> cells;

void dfs(int x, int y) {
  if (a[x][y] == '#' || mark[x][y]) {
    return;
  }
  mark[x][y] = 1;
  cells.push_back (make_pair (x, y));
  dfs(x, y - 1);
  dfs(x, y + 1);
  dfs(x - 1, y);
}

int dx[3] = {0, 0, 1};
int dy[3] = {-1, 1, 0};

set <ll> was;

int go (const vector <pii> &v, int x) {
  ll hash = 0;
  for (int i = 0; i < (int)v.size(); i++) {
    hash = hash * 239017 + v[i].first;
    hash = hash * 239017 + v[i].second;
  }
  if (!was.insert (hash).second) {
    return 0;
  }

//  for (int i = 0; i < (int)v.size(); i++) {
//    cerr << "(" << v[i].first << ", " << v[i].second << ") ";
//  }
//  cerr << endl;

  for (int t = 0; t < 3; t++) {
    vector <pii> nv = move (v, dx[t], dy[t]);
    int minx = 100, maxx = -1;
    for (int i = 0; i < (int)nv.size(); i++) {
      minx = min (minx, nv[i].first);
      maxx = max (maxx, nv[i].first);
    }
    if (maxx <= x) {
      assert (maxx == x);
      if (minx >= x || go (nv, x)) {
        return 1;
      }
    }
  }
  return 0;
}


void solve (int x, int y) {
  cells.clear();
  memset (mark, 0, sizeof (mark));
  dfs(x, y);

  int cnum = a[x][y] - '0';
  anscnt[cnum] = cells.size();

  for (int i = 0; i < 60; i++) {
    cells = move(cells, 0, 1);
  }
  sort (cells.begin(), cells.end());

  was.clear();
  ans[cnum] = go (cells, x);
}

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn = 1; tn <= nt; tn++) {
    printf ("Case #%d:\n", tn);
    fprintf (stderr, "Case #%d: \n", tn);

    int w, h;
    scanf ("%d %d", &w, &h);
    for (int i = 0; i < w; i++) {
      scanf ("%s", a[i]);
    }

    int d = -1;
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++) {
        if ('0' <= a[i][j] && a[i][j] <= '9') {
          solve (i, j);
          d = max(d, a[i][j] - '0');
        }
      }
    }
    for (int i = 0; i <= d; i++)
      printf ("%d: %d %s\n", i, anscnt[i], ans[i] ? "Lucky" : "Unlucky");
    cerr << num << endl;
  }

  return 0;
}
