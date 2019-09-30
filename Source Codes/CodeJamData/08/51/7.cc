/* GCJ'08
 * Author: Per Austrin
 */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
//#include <string>
//#include <map>
#include <vector>
#include <set>

using namespace std;
#define dprintf debug && printf
bool debug = false;

void init() {
}

typedef vector<int> vi;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

vi vert[10000], horz[10000];


void solve(int P) {
  
  int x = 5000, y = 5000, dir = 3;
    int L;
  scanf("%d", &L);
  for (int i = 0; i < 10000; ++i) horz[i].clear(), vert[i].clear();
  for (int l = 0; l < L; ++l) {
    char str[10000];
    int T;
    scanf("%s%d", str, &T);
    for (int i = 0; i < T; ++i) {
      for (int j = 0; str[j]; ++j) {
	switch (str[j]) {
	case 'R': dir = (dir+1) % 4; break;
	case 'L': dir = (dir+3) % 4; break;
	case 'F':
	  int nx = x + dx[dir], ny = y + dy[dir];
	  //	  printf("go (%d %d) -> (%d %d)\n", x-5000, y-5000, nx-5000, ny-5000);
	  if (y != ny) vert[min(y, ny)].push_back(x);
	  else horz[min(x, nx)].push_back(y); 
	  x = nx;
	  y = ny;
	  break;
	}
      }
    }
  }
  for (int i = 0; i < 10000; ++i) {
    sort(horz[i].begin(), horz[i].end());
    sort(vert[i].begin(), vert[i].end());
  }
  set<int> pockets[10000];
  for (int x = 0; x < 10000; ++x) {
    assert(horz[x].size() % 2 == 0);
    for (int j = 1; j+1 < horz[x].size(); j += 2) {
      int y1 = horz[x][j], y2 = horz[x][j+1];
      for (int y = y1; y < y2; ++y) pockets[x].insert(y);
    }
  }
  for (int y = 0; y < 10000; ++y) {
    assert(vert[y].size() % 2 == 0);
    for (int j = 1; j+1 < vert[y].size(); j += 2) {
      int x1 = vert[y][j], x2 = vert[y][j+1];
      for (int x = x1; x < x2; ++x) pockets[x].insert(y);
    }
  }
  int tot = 0;
  for (int x = 0; x < 10000; ++x) {
    tot += pockets[x].size();
  }

  fprintf(stderr, "went %d -> %d\n", P, tot);
  printf("Case #%d: %d\n", P, tot);
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}
