#include <iostream>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

const int INF = 1e9 + 314;

int dist(int base, int num, int i)
{
  int cnt = 0;
  i -= base;
  REP(j,num)
    cnt += abs(i+j);
  return cnt;
}

int eval(int r, int g, int b, int gi)
{
  int bi = gi + g;
  int center_b = bi + b / 2;
  if (center_b < 100) {
    bi += 100 - center_b;
  }

  int ri = gi - r;
  int center_r = ri + r / 2;
  if (center_r > -100) {
    ri -= center_r - (-100);
  }

  return dist(0, g, gi) + dist(100, b, bi) + dist(-100, r, ri);
}

int main()
{
  int r, g, b;
  cin >> r >> g >> b;

  int ans = INF;
  for (int i = -1000; i < 1000; i++) {
    ans = min(ans, eval(r, g, b, i));
  }

  cout << ans << endl;
  return 0;
}