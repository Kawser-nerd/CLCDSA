#include <cstdio>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int n;
int a[111111];

int main(void) {
  set<int> s;
  map<int, int> m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    m[a[i]] += 1;
    s.insert(a[i]);
  }

  int res = 0;
  for (auto&& x : s) {
    if (m[x] > x) res += m[x] - x;
    else if (m[x] < x) res += m[x];
  }
  printf("%d\n", res);
  return 0;
}