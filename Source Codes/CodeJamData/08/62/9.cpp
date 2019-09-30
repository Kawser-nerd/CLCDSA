#include <cstdio>
#include <sstream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

map < pair <vector <vector <int> >, int >, int> hoge;

int attack(vector <vector <int> > strength, int r, int c, int dir)
{
  int R = strength.size();
  int C = strength[0].size();

  pair <vector <vector <int> >, int > key(strength, dir);
  if (hoge.find(key) != hoge.end()) {
    return hoge[key];
  }

  int dx[5] = {0, -1, 1, 0, -100};
  int dy[5] = {-1, 0, 0, 1, -100};
  if (strength[r][c] <= 0) {
    return 0;
  }

  int x = c;
  int y = r;
  int maxs = 0;
  for (int d = 0; d < 4; d++) {
    if (x + dx[d] >= 0 && x + dx[d] < C &&
	y + dy[d] >= 0 && y + dy[d] < R &&
	maxs < strength[y + dy[d]][x + dx[d]]) {
      maxs = strength[y + dy[d]][x + dx[d]];
    }
  }
  if (maxs == 0) {
    return (1 << 30) + 1;
  }

  vector <vector <int> > newstrength = strength;
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (y != r || x != c) {
	int maxdir = -1;
	int maxs = 0;
	for (int d = 0; d < 4; d++) {
	  if (x + dx[d] >= 0 && x + dx[d] < C &&
	      y + dy[d] >= 0 && y + dy[d] < R &&
	      maxs < strength[y + dy[d]][x + dx[d]]) {
	    maxdir = d;
	    maxs = strength[y + dy[d]][x + dx[d]];
	  }
	}
	if (maxdir >= 0) {
	  newstrength[y + dy[maxdir]][x + dx[maxdir]] =
	    max(0, newstrength[y + dy[maxdir]][x + dx[maxdir]] - strength[y][x]);
	}
      } else {
	if (x + dx[dir] >= 0 && x + dx[dir] < C &&
	    y + dy[dir] >= 0 && y + dy[dir] < R) {
	  newstrength[y + dy[dir]][x + dx[dir]] =
	    max(0, newstrength[y + dy[dir]][x + dx[dir]] - strength[y][x]);
	}
      }
    }
  }

  int maxdays = 0;
  for (int d = 0; d < 5; d++) {
    maxdays = max(maxdays, 1 + attack(newstrength, r, c, d));
  }

  return hoge[key] = maxdays;
}

int main()
{
  char tmp[10000];
  int numcases;

  gets(tmp); sscanf(tmp, "%d", &numcases);

  for (int caseno = 0; caseno < numcases; caseno++) {
    int R, C ,r, c;
    gets(tmp); sscanf(tmp, "%d%d%d%d", &C, &R, &c, &r);
    r--; c--;

    vector <vector <int> > strength(R);
    for (int y = 0; y < R; y++) {
      strength[y].resize(C);
      gets(tmp); stringstream ss(tmp);
      for (int x = 0; x < C; x++) {
	ss >> strength[y][x];
      }
    }

    hoge.clear();
    int maxdays = 0;
    for (int d = 0; d < 5; d++) {
      maxdays = max(maxdays, attack(strength, r, c, d) - 1);
    }
    if (maxdays >= 1 << 30) {
      printf("Case #%d: forever\n", caseno + 1);
    } else {
      printf("Case #%d: %d day(s)\n", caseno + 1, maxdays);
    }
  }

  return 0;
}
