#include <cstdio>
#include <bitset>

static const int N = 2005;
int a[N];
std :: bitset <4000005> bs;

int main() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
  bs[0] = 1;
  for (int i = 0; i < n; ++ i) bs |= bs << a[i];
  int t = bs.count();
  if (t & 1) {
    (++ t) >>= 1;
    for (int i = 0; i <= 4000000; ++ i) {
      t -= bs[i];
      if (! t) {
        printf("%d\n", i); return 0;
      }
    }
  } else {
    t >>= 1;
    for (int i = 1; i <= 4000000; ++ i) {
      t -= bs[i];
      if (! t) {
        printf("%d\n", i); return 0;
      }
    }
  }
  return 0;
}