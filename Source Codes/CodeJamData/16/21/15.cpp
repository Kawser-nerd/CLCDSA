/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define IS(a, i) (((a) >> (i)) & 1)

const char *digit[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char s[2001];

typedef vector<unsigned> V;
void solve() {
  int mask = (1 << 10) - 1;
  V m(10), cnt_s(26), ans(10);
  vector<V> cnt(10, V(26));
  forn(i, 10)
    for (int j = 0; digit[i][j]; j++) {
      int c = digit[i][j] - 'A';
      m[i] |= 1 << c;
      cnt[i][c]++;
    }
  gets(s);
  for (int i = 0; s[i]; i++)
    cnt_s[s[i] - 'A']++;

  while (mask > 0)
    forn(i, 10) 
      if (IS(mask, i)) {
        unsigned x = m[i];
        forn(j, 10)
          if (i != j && IS(mask, j))
            x &= ~m[j];
        if (x) {
          int c = 0;
          while (!IS(x, c))
            c++;
          //printf("%d : %c [%d - %d]\n", i, 'A' + c, cnt_s[c], cnt[i][c]);
          while (cnt_s[c] > 0) {
            forn(j, 26)
              cnt_s[j] -= cnt[i][j];
            ans[i]++;
          }
          mask &= ~(1U << i);
        }          
      }
  forn(i, 10)
    while (ans[i]--)
      putchar('0' + i);
  puts("");
}

int main() {
  int n;
  scanf("%d ", &n);
  for (int i = 1; i <= n; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}