#include <stdio.h>
struct act {
  struct act *next;
} v[10000001], *rad[10000001];
int it[1<<25];
int main ()
{
  int t, i, j, k, l, e, r, n;
  long long y, open, close;
  scanf ("%d", &t);
  for (i = 1; i <= t; i++) {
    scanf ("%d%d%d", &e, &r, &n);
    for (j = 0; j <= 10000000; j++) rad[j] = NULL;
    for (j = 1; j <= n; j++) {
      scanf ("%d", &k);
      v[j].next = rad[k];
      rad[k] = &v[j];
    }
    memset (it, 0, sizeof (it));
    for (k = (1<<24); k; k >>= 1) it[k] = 1;
    for (l = (1<<24)+1+n; l; l >>= 1) it[l] = 1;
    y = 0;
    for (j = 10000000; j > 0; j--) {
      for (; rad[j]; rad[j] = rad[j]->next) {
        for (k = rad[j] - v + (1<<24); !(k & 1) || !it[k-1]; k >>= 1) {}
        for (k--; k < (1<<24); k = k + k + (it[k+k+1] ? 1 : 0)) {}
        for (l = rad[j] - v + (1<<24); !!(l&1) || !it[l+1]; l >>= 1) {}
        for (l++; l < (1<<24); l = l + l + (it[l+l] ? 0 : 1)) {}
        if (l > (1<<24) + n) l = (1<<25);
        if (k == (1<<24)) k = 0;
        open = r * (long long) (rad[j] - v + (1<<24) - k) > e ? e :
          r * (long long) (rad[j] - v + (1<<24) - k);
        close = e - r * (long long) (l - (rad[j] - v + (1<<24))) < 0 ? 0 :
          e - r * (long long) (l - (rad[j] - v + (1<<24)));
        if (open > close) y += (open - close) * j;
        //fprintf (stderr, "%d: %d < %d ", j, k - (1<<24), rad[j] - v);
        //fprintf (stderr, "< %d, %lld - %lld\n", l - (1<<24), open, close);
        for (k = rad[j] - v + (1<<24); k; k >>= 1) it[k] = 1;
      }
    }
    printf ("Case #%d: %lld\n", i, y);
  }
  return 0;
}
