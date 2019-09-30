
#include <stdio.h>

static int N, M;
static int malted[2048];
static int sol[2048];
static int mark[2048];
static int pref[2048][2048];


int resolve (void)
{
  int i, j, marcou = 0;

  for(i = 0; i < M; i++) mark[i] = 0;
  for(j = 0; j < N; j++) sol[j] = 0;

  do {
    marcou = 0;
    for(i = 0; i < M; i++) {
      if (mark[i]) continue;
      for(j = 0; j < N; j++) {
        if (pref[i][j] && !sol[j]) break;
      }
      if (j < N) continue;
      if (malted[i] != -1) {
        sol[malted[i]] = 1;
        mark[i] = 1;
        marcou = 1;
        break;
      } else return 0;
    }
  } while (marcou);
  return 1;
}


int main (void)
{

  int c, i, j, T, C, resp;
  scanf ("%d", &C);

  for (c = 1; c <= C; c++) {

    scanf ("%d", &N);
    scanf ("%d", &M);

    for(i = 0; i < M; i++) malted[i] = -1;
    for (i = 0; i < M; i++)
      for(j = 0; j < N; j++)
        pref[i][j] = 0;

    for (i = 0 ; i < M; i++) {
      scanf ("%d", &T);
      while (T--) {
        int x, y;
        scanf ("%d", &x);
        scanf ("%d", &y);
        if (y == 1) malted[i] = x - 1;
        else pref[i][x-1] = 1;
      }
    }

    resp = resolve ();
    printf ("Case #%d: ", c);
    if (!resp) printf ("IMPOSSIBLE\n");
    else {
      for (j = 0; j < N; j++) {
        if (j != 0) printf (" ");
        printf ("%d", sol[j]);
      }
      printf ("\n");
    }
  }

  return 0;
}
