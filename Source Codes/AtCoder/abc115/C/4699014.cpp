#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;
using ll = long long int;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> h(n, 0);
  for(int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  sort(h.begin(), h.end());
  reverse(h.begin(), h.end());
  int be = h[0];
  for(int i = 0; i < n - k + 1; i++)
  {
    int hmax = h[i];
    int hmin = h[i + k - 1];
    be = min(be, hmax - hmin);
  }
  cout << be << endl;
}