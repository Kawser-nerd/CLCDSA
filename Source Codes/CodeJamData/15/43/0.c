#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

int d[20];

unsigned long long word_hashes[5000];
int words[5000];

void solve (void) {
  int n;
  assert (scanf ("%d\n", &n) == 1);

  int i;
  int tot_words = 0;

  static char s[1000000];
  for (i = 0; i < n; i++) {
    gets (s);
    int p = 0;
    while (1) {
      while (s[p] && s[p] == ' ') { p ++; }
      if (!s[p]) { break; }
      unsigned long long hash = 0;
      while (s[p] && s[p] != ' ') { 
        hash = hash * 533 + s[p] - 'a' + 1;
        p ++;
      }
      int j;
      for (j = 0; j < tot_words; j++) {
        if (word_hashes[j] == hash) {
          words[j] |= (1 << i);
          break;
        }
      }
      if (j == tot_words) {
        word_hashes[tot_words] = hash;
        words[tot_words] = (1 << i);
        assert (tot_words < 5000);
        tot_words ++;
      }
    }
  }

  int best = tot_words;
  int nn = 0;
  for (nn = 0; nn < (1 << n); nn++) {
    if ((nn & 1) || !(nn & 2)) { continue; }
    
    int cur = 0;
    for (i = 0; i < tot_words; i++) {
      if ((words[i] & nn) && (words[i] & ~nn)) {
        cur ++;
      }
    }

    if (cur < best) { best = cur; }

  }
  printf ("%d\n", best);
}

int main () {
  int _;
  assert (scanf ("%d\n", &_) == 1);
  int __;
  for (__ = 0; __ < _; __ ++) {
    printf ("Case #%d: ", __ + 1);
    solve ();
  }
  return 0;
}
