#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <execinfo.h>

void my_sighandler (int sig) {
  void *array[100];
  size_t size;
  fprintf(stderr, "Error: signal %d:\n", sig);
  size = backtrace(array, 10);
  backtrace_symbols_fd(array, size, 2);
  exit(1);
}
int n;
int a[50000];
double inv[50000];
#define EPS 1e-9
#define EPS2 1e-7

void solve (void) {
  scanf ("%d", &n);
  int i, j;
  for (i = 0; i < n; i++) {
    scanf ("%d", &a[i]);
  }
  double best = 1e100;
  for (i = 0; i < n; i++) {
    double m = (a[n - 1] - a[0]);
    double M = 0;
    for (j = 0; j < n; j++) if (i != j) {
      double b;
      if (i > j) {
        b = (a[i] - a[j]) * inv[i - j];
        if (b < m) { m = b; }
      } else {
        b = (a[j] - a[i]) * inv[j - i];
        if (b > M) { M = b; }
      }
    }
    if (m < M - EPS) {
      continue;
    }
    if (m < M) { m = M; }
    while (m - M > EPS2) {
      double x = (m + M) * 0.5;
      double e1 = 0;
      for (j = 0; j < i; j++) {
        double b = a[i] + (j - i) * x - a[j];
        assert (b >=  - EPS);
        if (e1 < b) { e1 = b; }
      }
      double e2 = 0;
      for (j = i; j < n; j++) {
        double b = a[i] + (j - i) * x - a[j];
        assert (b >=  - EPS);
        if (e2 < b) { e2 = b; }
      }
      if (e1 > e2) {
        M = x;
      } else {
        m = x;
      }
    }
    double e = 0;
    for (j = 0; j < n; j++) {
      double b = a[i] + (j - i) * m - a[j];
      assert (b >= -EPS);
      if (b > e) { e = b; }
    }
    if (best > e) {
      best = e;
    }
  }
  printf (" %lf\n", best / 2);
}


int main () {
  int i;
  for (i = 1; i < 50000; i++) {
    inv[i] = 1.0 / i;
  }
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
