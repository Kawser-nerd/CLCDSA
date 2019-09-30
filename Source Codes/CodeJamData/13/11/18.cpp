#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

long long r,t;
int T;

bool check(long long k) {
  if (k == 0) return true;
  if (t/r < k * 2) return false;
  if (t/k < k * 2 - 1) return false;
  return k * r * 2 + k * (k * 2 - 1) <= t;
}

void solveCase(int it) {
  cin >> r >> t;
  long long low = 0,high = t,ans = 0;
  while (low <= high) {
    long long mid = (low + high)/2;
    if (check(mid)) {
      ans = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }
  printf("Case #%d: %lld\n", it, ans);
}

int main() {
  scanf("%d", &T);
  for (int it = 1; it <= T; it++) solveCase(it);
}
