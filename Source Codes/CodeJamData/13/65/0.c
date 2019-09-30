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

int r[100][100][2];
int n;
int a[10000];

#define MOD 10007

void solve (void) {
  scanf ("%d", &n);
  assert (n <= 100);
  int i, j, k;
  for (i = 0; i < n; i++) {
    scanf ("%d", &a[i]);
  }
  int ok = 0;
  for (i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      ok = 1;
      break;
    }
  }
  if (!ok) {
    printf (" 1\n");
    return;
  }
  memset (r, 0, sizeof (r));
  int res = 0;
  int fac = 1;
  for (i = 0; i < n; i++) {
    r[i][1][0] = 1;
    for (j = 0; j < i; j++) {
      if (a[i] > a[j]) {
        r[i][1][1] ++;
      }
    }
    int count = 0;
    for (j = i - 1; j >= 0; j--) {
      if (a[i] > a[j]) {
        for (k = 0; k < n; k++) {
          r[j][k][1] += r[j][k][0];
          if (r[j][k][1] >= MOD) {
            r[j][k][1] -= MOD;
          }
        }
        count ++;
      } else {
        for (k = 2; k < n; k++) {
          r[i][k][0] += r[j][k - 1][0];
          if (r[i][k][0] >= MOD) {
            r[i][k][0] -= MOD;
          }
          r[i][k][1] = (r[i][k][1] + r[j][k - 1][1] + count * r[j][k - 1][0]) % MOD;
        }
      }
    }
  }
  fac = 1;
  for (i = n - 1; i >= 1; i--) {
    for (j = 0; j < n; j++) {
      res = (res + r[j][i][1] * fac) % MOD;
    }
    fac = (fac * (n - i)) % MOD;
  }
  printf (" %d\n", res);
  /*for (i = 0; i < n; i++) {
    for (j = 1; j < n; j++) {
      printf ("%d:%d ", r[i][j][0], r[i][j][1]);
    }
    printf ("\n");
  }*/
    
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
