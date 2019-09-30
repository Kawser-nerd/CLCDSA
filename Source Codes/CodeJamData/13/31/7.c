#include <stdio.h>
#include <string.h>

char s[2222222];
int r[2222222];

int chk(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 0;
  return 1;
}

int main() {
  int T, C = 1;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%s%d", s, &n);
    int i, j = strlen(s), last = -1;
    memset(r, 0, sizeof(r));
    r[0] = chk(s[0]);
    for (i = 1; s[i]; i++)
      r[i] += r[i - 1] + chk(s[i]);
    unsigned long long ans = 0;
    for (i = 0; s[i + n - 1]; i++)
      if (r[i + n - 1] - r[i] + chk(s[i]) == n) {
        int left = i - last - 1;
        int right = j - i - n;
        ans += (unsigned long long)(right + 1) * (unsigned long long)(left + 1);
        last = i;
      }
    printf("Case #%d: %llu\n", C++, ans);
  }
  return 0;
}
