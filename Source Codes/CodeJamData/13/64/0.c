#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <execinfo.h>
#include <time.h>
void my_sighandler (int sig) {
  void *array[100];
  size_t size;
  fprintf(stderr, "Error: signal %d:\n", sig);
  size = backtrace(array, 10);
  backtrace_symbols_fd(array, size, 2);
  exit(1);
}

int a[1000000][4];
int n, d, k;

int do_try_1 (int *q, int p, int f, int l) {
  if (!l) { return 0; }
  while (l) {
    int i, j;
    int ok = 0;
    for (i = 0; i < d && !ok; i++)
      for (j = 0; j < p; j++) {
        if (a[f][i] == q[j]) {
          ok = 1;
          break;
        }
      }
    if (ok) {
      f --;
      l --;
    } else {
      int max = l;
      if (p < k) {
        for (i = 0; i < d; i++) {
          q[p] = a[f][i];
          int v = do_try_1 (q, p + 1, f - 1, l - 1);
          if (!v) { return 0; }
          if (v < max) { max = v; }
        }
      }
      return max;
    }
  }
  return 0;
}

int do_try (int f, int l) {
  static int q[4];
  return do_try_1 (q, 0, f, l);
}

void solve (void) {
  scanf ("%d %d %d", &n, &d, &k);
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < d; j++) {
      scanf ("%d", &a[i][j]);
    }
  }
  int l = n >= k ? k : n;
  int r = n + 1;
  int bl = 0;
  while (r - l > 1) {
    int x = (r + l) / 2;
    int ii;
    int ok = 0;
    int i = 0;
    while (i + x <= n) {
      int t = do_try (i + x - 1, x);
      if (!t) {
        ok = 1;
        ii = i;
        break;
      } else {
        assert (t > 0);
        i += t;
      }
    }
    if (ok) { l = x; bl = ii; }
    else { r = x; }
  }
  printf (" %d %d\n", bl, bl + l - 1);
}

int main () {
  signal (SIGSEGV, my_sighandler);
  signal (SIGFPE, my_sighandler);
  signal (SIGABRT, my_sighandler);
  int _, __;
  assert (scanf ("%d", &_) == 1);
  for (__ = 0; __ < _; __ ++ ) {
    printf ("Case #%d:", __ + 1);
    solve ();
  }
  return 0;
}
