#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const* argv[])
{
  double a, b, c, d, e, f;

  cin >> a >> b >> c >> d >> e >> f;

  c = c - a;
  d = d - b;
  e = e - a;
  f = f - b;

  printf("%.3f\n", abs((c * f - d * e) / 2));

  return 0;
}