#include <stdio.h>
#include <string.h>

double f[1111111];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq=1;qq<=tt;qq++) {
    printf("Case #%d: ", qq);
    char s[42];
    scanf("%s", s);
    int n = strlen(s);
    f[(1 << n)-1] = 0.0;
    for (int t=(1 << n)-2;t>=0;t--) {
      f[t] = 0;
      int cnt = 0;
      for (int i=0;i<n;i++) {
        int j = i;
        int cur = n;
        while (t & (1 << j)) {
          j++;
          if (j == n) j = 0;
          cur--;
        }
        f[t] += f[t + (1 << j)] + cur;
        cnt++;
      }
      f[t] /= cnt;
    }
    int t = 0;
    for (int i=0;i<n;i++)
      if (s[i] == 'X') t |= (1 << i);
    printf("%.17lf\n", f[t]);
    fflush(stdout);
  }
  return 0;
}
