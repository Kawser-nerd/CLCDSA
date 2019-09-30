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

int a[31], b[31];

int main(void)
{
  a[0] = 3; b[0] = 1;
  for (int i = 1; i <= 30; i++) {
    a[i] = (a[i-1]*a[i-1] + 5*b[i-1]*b[i-1]) % 1000;
    b[i] = 2*a[i-1]*b[i-1] % 1000;
  }
  int T;
  cin >> T;
  for (int c = 1; c <= T; c++) {
    int n;
    cin >> n;
    int x = 1, y = 0;
    for (int i = 0; i <= 30; i++)
      if ((n>>i)&1) {
	int nx = (x*a[i] + 5*y*b[i]) % 1000;
	int ny = (x*b[i] + y*a[i]) % 1000;
	x = nx; y = ny;
      }
    int ans = (2*x + 999) % 1000;
    printf("Case #%d: %03d\n", c, ans);
  }
}
