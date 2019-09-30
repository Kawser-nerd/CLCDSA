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

int main(void)
{
  int T;
  cin >> T;
  string line;
  for (int c = 1; c <= T; c++) {
    int n;
    cin >> n;
    vector <long long> x(n), y(n);
    for (int i = 0; i < n; i++)
      cin >> x[i];
    for (int i = 0; i < n; i++)
      cin >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long long ans = 0;
    for (int i = 0; i < n; i++)
      ans += x[i] * y[n-1-i];
    printf("Case #%d: %Ld\n", c, ans);
  }
}
