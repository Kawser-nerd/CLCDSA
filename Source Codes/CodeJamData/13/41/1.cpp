#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

const int md = 1000002013;

int cost(int n, int len) {
  int a = n + (n - len + 1);
  int b = len;
  if (a % 2 == 0) a /= 2;
  else b /= 2;
  return (long long)a * b % md;
}

pair <int, int> a[424242], b[424242];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq=1;qq<=tt;qq++) {
    printf("Case #%d: ", qq);
    int n, m;
    scanf("%d %d", &n, &m);
    long long ans1 = 0, ans2 = 0;
    for (int i=0;i<m;i++) {
      int q, w, e;
      scanf("%d %d %d", &q, &w, &e);
      a[i] = make_pair(q, e);
      b[i] = make_pair(w, e);
      ans1 = (ans1 + (long long)e * cost(n, w-q)) % md;
    }
    sort(a, a+m);
    sort(b, b+m);
    for (int i=0;i<m;i++) {
      int where = b[i].first;
      int count = b[i].second;
      for (int j=m-1;j>=0;j--)
        if (a[j].first <= where) {
          int add = count;
          if (a[j].second < add) add = a[j].second;
          ans2 = (ans2 + (long long)add * cost(n, where-a[j].first)) % md;
          a[j].second -= add;
          count -= add;
        }
    }
    printf("%d\n", (ans1 - ans2 + md) % md);
  }
  return 0;
}
