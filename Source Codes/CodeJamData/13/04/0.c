#include <stdio.h>
#include <string.h>

int n, T[201], K[201], x[201][400], need[402], cnt[402];
int lock[201], tcnt[402], tneed[402], tT[201], lockv = 1;

int IsLoop (int chest, int dest)
{
  int y, z;
  if (lock[chest] < lockv) {
    lock[chest] = lockv;
    for (y = 0; y < K[chest]; y++) {
      for (z = 1; z <= n; z++) {
        if (x[chest][y] == dest ||
            (x[chest][y] == tT[z] && IsLoop (z, dest))) return 1;
      }
    }
  }
  return 0;
}

int main ()
{
  int t, i, k, j, l, m, tl;
  scanf ("%d", &t);
  for (i = 1; i <= t; i++) {
    scanf ("%d%d", &k, &n);
    //fprintf (stderr, "%d %d %d\n", i, n, k);
    memset (cnt, 0, sizeof (cnt));
    memset (need, 0, sizeof (need));
    for (j = 1; j <= k; j++) {
      scanf ("%d", &l);
      cnt[l]++;
    }
    for (j = 1; j <= n; j++) {
      scanf ("%d%d", &T[j], &K[j]);
      need[T[j]]++;
      for (l = 0; l < K[j]; l++) scanf ("%d", &x[j][l]);
    }
    memset (lock, 0, sizeof (lock));
    printf ("Case #%d:", i);
    for (j = 0; j < n; j++) {
      for (l = 1; l <= n; l++) {
        if (T[l] < 0 || !cnt[T[l]]) continue;
        memcpy (tneed, need, sizeof (tneed));
        memcpy (tcnt, cnt, sizeof (tcnt));
        memcpy (tT, T, sizeof (tT));
        tl = l;
        do {
          for (m = 0; m < K[tl]; m++) tcnt[x[tl][m]]++;
          tneed[tT[tl]]--;
          tcnt[tT[tl]]--;
          tT[tl] = -1;
          lockv++;
          for (tl = 1; tl <= n && (tT[tl] < 0 ||
                         (tneed[tT[tl]] > tcnt[tT[tl]] &&
                           !(tcnt[tT[tl]] && IsLoop (tl, tT[tl]))));
               tl++) {}
        } while (tl <= n);
        for (tl = 1; tl <= n && tT[tl] < 0; tl++) {}
        if (tl > n) break; // Yes, opening 'l' works
      }
      if (l > n) break;
      printf (" %d", l);
      need[T[l]]--;
      cnt[T[l]]--;
      T[l] = -1;
      for (m = 0; m < K[l]; m++) cnt[x[l][m]]++;
    }
    if (j < n) printf (" IMPOSSIBLE");
    printf ("\n");
  }
  return 0;
}
