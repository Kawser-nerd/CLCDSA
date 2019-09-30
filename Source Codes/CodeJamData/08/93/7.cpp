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

int grid[100][100];

int main(void)
{
  int NUM_CASES;
  cin >> NUM_CASES;
  for (int c = 1; c <= NUM_CASES; c++) {
    int X, Y;
    cin >> X >> Y;
    for (int x = 0; x < X; x++)
      for (int y = 0; y < Y; y++)
	cin >> grid[x][y];
    int ans = 0;
    int yoff = (Y % 3 == 0 ? 1 : 0);
    int R = (X-1)/2;
    int r;
    if (R % 3 == 1) {
      r = (R-1)/3;
      for (int y = yoff; y < Y; y += 3) {
	for (int x = 0; x <= r; x++)
	  ans += grid[3*x][y];
	for (int x = r; x <= 2*r; x++)
	  ans += grid[2+3*x][y];
	for (int x = 0; x <= 2*r; x++)
	  ans -= grid[1+3*x][y];
      }
    }
    else if (R % 3 == 2) {
      r = (R-2)/3;
      for (int y = yoff; y < Y; y += 3)
	for (int x = 0; x <= r; x++)
	  ans += grid[1+3*x][y] - grid[3*x][y];
    }
    else {
      r = (R-3)/3;
      for (int y = yoff; y < Y; y += 3) {
	for (int x = 0; x <= 2*r+2; x++)
	  ans += grid[3*x][y];
	for (int x = 0; x <= r; x++)
	  ans -= grid[1+3*x][y];
	for (int x = r+1; x <= 2*r+1; x++)
	  ans -= grid[2+3*x][y];
      }
    }
    printf("Case #%d: %d\n", c, ans);
  }
}
