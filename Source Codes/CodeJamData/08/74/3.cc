#include <iostream>
using namespace std;

int r, c;
bool u[17][17];
int m[17][17][2];

bool dead(int kx, int ky)
{
  if (!u[kx][ky])
    return false;
  u[kx][ky] = false;
  bool d = true;
  for (int x1 = kx - 1; x1 <= kx + 1; x1++)
    for (int y1 = ky - 1; y1 <= ky + 1; y1++)
      if (dead(x1, y1)) {
	d = false;
	break;
      }
  u[kx][ky] = true;
  return d;
}

int main()
{
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; ++test) {
    cin >> r >> c;
    int kx = 0, ky = 0;
    for (int x = 0; x <= c + 1; ++x)
      for (int y = 0; y <= r + 1; ++y)
	u[x][y] = false;
    for (int y = 1; y <= r; ++y)
      for (int x = 1; x <= c; ++x) {
	char k;
	cin >> k;
	u[x][y] = (k != '#');
	if (k == 'K')
	  kx = x, ky = y;
      }
    if (dead(kx, ky))
      cout << "Case #" << test << ": B" << endl;
    else
      cout << "Case #" << test << ": A" << endl;
  }
}
