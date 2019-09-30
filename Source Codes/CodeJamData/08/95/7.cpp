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

int best[226][1<<15];

int main(void)
{
  int NUM_CASES;
  cin >> NUM_CASES;
  for (int c = 1; c <= NUM_CASES; c++) {
    cin >> X >> Y; int N = 1<<Y;
    grid.clear(); grid.resize(X);
    for (int i = 0; i < X; i++) {
      cin >> grid[i];
    }
    memset(best, 0, sizeof(best));
    for (int done = 1; done <= X*Y; done++) {
      int x = (done-1)/Y, y = (done-1)%Y;
      for (int m = 0; m < N; m++) {
	int prev = best[done-1][m];
	if (grid[x][y] != '.') { // try competing
	  int tans = prev + 4, newm = ((~N)&(m<<1))|1;
	  if (y != 0 && (m&1))
	    tans -= 2;
	  if ((m>>(Y-1))&1)
	    tans -= 2;
	  best[done][newm] = max(best[done][newm], tans);
	}
	if (grid[x][y] != '#') { // try sitting
	  int newm = ((~N)&(m<<1));
	  best[done][newm] = max(best[done][newm], prev);
	}
      }
    }
    int ans = 0;
    for (int m = 0; m < N; m++)
      ans = max(ans, best[X*Y][m]);
    printf("Case #%d: %d\n", c, ans);
  }
}
