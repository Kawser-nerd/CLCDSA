#include <bits/stdc++.h>

using namespace std;

char s[1234567], st[1234567];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    scanf("%s", s);
    int n = strlen(s);
    int ans = 0;
    st[0] = 'Z';
    for (int i = 0; i < n; i++) {
      if (s[i] != st[ans]) {
        st[++ans] = s[i];
      } else {
        ans--;
      }
    }
    printf("%d\n", 5 * (n - ans / 2));
  }
  return 0;
}
