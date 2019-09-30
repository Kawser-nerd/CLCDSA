#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int f[6][6];
int n, m;
int total = 0;

string unify()
{
  vector<string> shifts;

  vector<string> rows;
  for (int i = 0; i < n; i++)
    {
      stringstream ss;
      for (int j = 0; j < m; j++)
        {
          ss << f[i][j];
        }
      string s;
      ss >> s;
      rows.push_back(s);
    }
}

bool check()
{
  for (int x = 0; x < n; x++)
    {
      for (int y = 0; y < m; y++)
        {
          int cnt = 0;
          int here = f[x][y];
          if (x != 0)
            cnt += here == f[x - 1][y];
          if (x != n - 1)
            cnt += here == f[x + 1][y];
          cnt += here == f[x][(y + 1) % m];
          cnt += here == f[x][(y - 1 + m) % m];
          if (cnt != here)
            return false;
        }
    }
  return true;
}

bool check2(int x, int y)
{
  int cnt = 0;
  int here = f[x][y];
  int zeros = 0;
  if (here == 0)
    return true;
  if (x != 0)
    {
      cnt += here == f[x - 1][y];
      zeros += f[x - 1][y] == 0;
    }
  if (x != n - 1)
    {
      cnt += here == f[x + 1][y];
      zeros += f[x + 1][y] == 0;
    }
  cnt += here == f[x][(y + 1) % m];
  zeros += f[x][(y + 1) % m] == 0;
  cnt += here == f[x][(y - 1 + m) % m];
  zeros += f[x][(y - 1 + m) % m] == 0;
  if (zeros == 0 && cnt < here)
    return false;
  return cnt <= here;
}

void gen(int x, int y)
{
  //cerr << x << " " << y << "\n";
  if (x == n || y == m)
    {
      if (check())
        {
          total++;
          cerr << "========\n";
          for (int i = 0; i < n; i++)
            {
              for (int j = 0; j < m; j++)
                cerr << f[i][j];
              cerr << "\n";
            }
        }
      return;
    }
  int nextX = x + (y == m - 1);
  int nextY = (y + 1) % m;
  //int nextX = (x + 1) % n;
  //int nextY = y + (x == n - 1);
  for (int here = 3; here >= 1; here--)
    {
      f[x][y] = here;
      bool ok = check2(x, y);
      if (x > 0)
        ok &= check2(x - 1, y);
      ok &= check2(x, (y - 1 + m) % m);
      ok &= check2(x, (y + 1) % m);
      /*
      if (y == m - 1)
        ok &= check
      */
      if (ok)
        gen(nextX, nextY);
    }
  f[x][y] = 0;
}


int main(int argc, char* argv[])
{
  n = 3;
  m = 5;
  n = atoi(argv[1]);
  m = atoi(argv[2]);
  gen(0, 0);
  //cout << total << "\n";
}
