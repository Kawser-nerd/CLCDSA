// Yen-Ming Lee <leeym@leeym.com>
// http://code.google.com/codejam/contest/dashboard?c=2418487#s=p1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int verbose = 0, debug = 0;

int max(int a, int b)
{
  return a > b ? a : b;
}

int min(int a, int b)
{
  return a < b ? a : b;
}

int solve(int E, int M, int R, int N, int n, int V[])
{
  if (n == N)
    return 0;
  if (verbose) {
    int i = 0;
    for (i = 0; i < n; i++)
      fprintf(stderr, "  ");
    fprintf(stderr, "solve(%d, %d, %d, %d, %d, [", E, M, R, N, n);
    for (i = n; i < N; i++)
      fprintf(stderr, " %d", V[i]);
    fprintf(stderr, " ])\n");
  }
  int e, Y = 0;
  for (e = 0; e <= E; e++) {
    int v = V[n];
    int y = e * v + solve(min(M, E - e + R), M, R, N, n + 1, V);
    Y = max(Y, y);
  }
  return Y;
}

int main(int argc, char *argv[])
{
  int ch;
  while ((ch = getopt(argc, argv, "vd")) != -1) {
    switch (ch) {
    case 'v':
      verbose = 1;
      break;
    case 'd':
      debug = 1;
      break;
    }
  }
  argc -= optind;
  argv += optind;

  int t, T;
  scanf("%d\n", &T);

  for (t = 1; t <= T; t++) {
    fprintf(stderr, "Case #%d/%d\n", t, T);
    int E, R, N;
    scanf("%d %d %d\n", &E, &R, &N);
    int n, V[N];
    for (n = 0; n < N; n++)
      scanf("%d", &V[n]);
    scanf("\n");
    if (verbose) {
      fprintf(stderr, "\tE:%d R:%d N:%d\n\t", E, R, N);
      for (n = 0; n < N; n++)
        fprintf(stderr, " %d", V[n]);
      fprintf(stderr, "\n");
    }
    printf("Case #%d: %d\n", t, solve(E, E, R, N, 0, V));
  }
}
