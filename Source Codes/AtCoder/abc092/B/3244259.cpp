#include <cstdio>

using namespace std;

int main() {
  int n, d, x;
  scanf("%d%d%d", &n, &d, &x);

  int a;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    for (int j = 1; j <= d; j += a) x++;
  }

  printf("%d\n", x);
  return 0;
}