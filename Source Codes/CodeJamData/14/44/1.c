#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int a[20000];
int b[20000];

int cmp (const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

char s[100][100];
int n, m;

int ptr[200];

int gb;
long long gc;

void slv (void) {
  int v = 0;
  int j, k;
  for (j = 0; j < m; j++) {
    int best = 0;
    for (k = j - 1; k >= 0; k--) {
      if (ptr[j] == ptr[k]) {
        int c = 0;
        while (s[j][c] && s[j][c] == s[k][c]) {
          c ++;
        }
        if (c + 1 > best) { best = c + 1; }
      }
    }
    v += strlen (s[j]) - best + 1;
  }
  if (v > gb) {
    gb = v;
    gc = 1;
  } else if (v == gb) {
    gc ++;
  }
}

void cou (int x) {
  if (x == m) {
    slv ();
    return;
  }
  int i;
  for (i = 0; i < n; i++) {
    ptr[x] = i; 
    cou (x + 1);
  }
 
}

void solve (void) {
  gb = -1;
  scanf ("%d %d\n", &m, &n);
  int i;
  for (i = 0; i < m; i++) {
    assert (scanf ("%s\n", s[i]) == 1);
  }
  cou (0);
  printf (" %d %d\n", gb, (int)(gc % 1000000007));
}

int main () {
  int _;
  assert (scanf ("%d", &_) == 1);
  int __;
  for (__ = 0; __ < _; __ ++) {
    printf ("Case #%d:", __ + 1);
    solve ();
  }
  return 0;
}
