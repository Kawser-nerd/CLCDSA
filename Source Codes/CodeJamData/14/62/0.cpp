#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

long long solve(vector <int> a, int moves) {
  int sz = a.size();
  if (sz == 1) {
    long long res = 1;
    for (long long i = 1; i <= moves; i++) {
      res *= i;
    }
    return res;
  }
  int ids[5];
  int cnt = 0;
  for (int i = 0; i < sz; i += 2) {
    if ((a[i] & 1) == 1 || a[i + 1] != a[i] + 1) {
      ids[cnt++] = i;
      if (cnt >= 3) {
        return 0;
      }
    }
  }
  if (cnt <= 1) {
    vector <int> b;
    for (int i = 0; i < sz; i += 2) {
      b.push_back(a[i] >> 1);
    }
    return solve(b, moves + cnt);
  }
  long long res = 0;
  for (int x = ids[0]; x < ids[0] + 2; x++) {
    for (int y = ids[1]; y < ids[1] + 2; y++) {
      swap(a[x], a[y]);
      bool ok = true;
      for (int q = 0; q < 2; q++) {
        if ((a[ids[q]] & 1) == 1 || a[ids[q] + 1] != a[ids[q]] + 1) {
          ok = false;
          break;
        }
      }
      if (ok) {
        vector <int> b;
        for (int i = 0; i < sz; i += 2) {
          b.push_back(a[i] >> 1);
        }
        res += solve(b, moves + 1);
      }
      swap(a[x], a[y]);
    }
  }
  return res;
}

vector <int> a;

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    fflush(stdout);
    int k;
    scanf("%d", &k);
    int n = (1 << k);
    a.resize(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      a[i]--;
    }
    cout << solve(a, 0) << endl;
    fflush(stdout);
  }
  return 0;
}
