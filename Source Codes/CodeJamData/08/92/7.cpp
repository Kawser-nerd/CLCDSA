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

int gcd(int a, int b)
{
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  int tmp;
  while (a != 0)
    {
      tmp = a;
      a = b % a;
      b = tmp;
    }
  return b;
}

int howmany(int x, int dx, int X) {
  if (dx == 0) return 1<<30;
  if (dx < 0) {
    dx = -dx;
    X = x;
  }
  else
    X -= x+1;
  return 1 + X / dx;
}

int main(void)
{
  int NUM_CASES;
  cin >> NUM_CASES;
  for (int c = 1; c <= NUM_CASES; c++) {
    int X, Y, x1, y1, x2, y2, x, y;
    cin >> X >> Y >> x1 >> y1 >> x2 >> y2 >> x >> y;
    long long ans = 0;
    cerr << "Case " << c << endl;
    if (x1*y2 != x2*y1) {
      while (1) {
	ans += min(howmany(x, x2, X), howmany(y, y2, Y));
	x += x1; y += y1;
	if (!(0 <= x && x < X && 0 <= y && y < Y)) {
	  x -= x1; y -= y1;
	  
	  bool good = false;
	  x += x2; y += y2;
	  while (0 <= x && x < X && 0 <= y && y < Y) {
	    int nx = x + x1, ny = y + y1;
	    if (0 <= nx && nx < X && 0 <= ny && ny < Y) {
	      x = nx; y = ny; good = true; break;
	    }
	    x += x2; y += y2;
	  }
	  if (!good) break;
	}
      }
    }
    else {
      if (x1 == 0) {
	swap(X, Y); swap(x1, y1); swap(x2, y2); swap(x, y);
      }
      int dx = gcd(x1, x2), dy = y1*dx/x1;
      int ds[2]; ds[0] = x1/dx, ds[1] = x2/dx;
      int Sup = min(howmany(x, dx, X), howmany(y, dy, Y)) - 1;
      int Sdown = min(howmany(x, -dx, X), howmany(y, -dy, Y)) - 1;
      int S = Sup+Sdown+1;
      cerr << Sup << " " << Sdown << " " << S << endl;
      vector <bool> visited(S);
      queue <int> q;
      visited[Sdown] = true;
      q.push(Sdown);
      while (!q.empty()) {
	int s = q.front(); q.pop();
	for (int k = 0; k < 2; k++) {
	  int ns = s + ds[k];
	  if (0 <= ns && ns < S && !visited[ns]) {
	    visited[ns] = true;
	    q.push(ns);
	  }
	}
      }
      for (int i = 0; i < S; i++)
	if (visited[i]) ans++;
    }
    printf("Case #%d: %Ld\n", c, ans);
  }
}
