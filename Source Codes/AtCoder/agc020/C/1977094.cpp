#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <map>
#include <set>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 1010 * 2010;

int main() {
  int n;
  cin >> n;
  vi a(n);
  int s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  bitset<maxn> u;
  u[0] = true;
  for (int i = 0; i < n; ++i)
    u |= (u << a[i]);
  int res = -1;
  for (int i = maxn - 1; i >= 0; --i) if (u[i]) {
//    cerr << i << "\n";
    if (abs(2 * i - s) < abs(2 * res - s))
      res = i;
  }
  cout << res << "\n";
  return 0;
}