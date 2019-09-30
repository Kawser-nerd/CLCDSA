#include <stdio.h>
#include <string.h>

int t, n, m, i, j, ocnt[1000001], stack[1000001], o, e, p, result;

int main ()
{
  scanf ("%d", &t);
  for (i = 1; i <= t; i++) {
    scanf ("%d%d", &n, &m);
    memset (ocnt, 0, sizeof (ocnt));
    //memset (ecnt, 0, sizeof (ecnt));
    result = 0;
    for (; m > 0; m--) {
      scanf ("%d%d%d", &o, &e, &p);
      result = (result +
        (e-o)*(long long)(n+n-e+o+1)/2%1000002013
        * (long long) p %1000002013)
        %1000002013;
      ocnt[o] += p;
      ocnt[e] -= p;
      //printf ("Cost=%d %d,%d,%d,%d\n", (e-o)*(n+n-e+o+1)/2*p, n, e, o, p);
    }
    p = 0;
    o = 0;
    //printf ("%d ", result);
    for (e = 1; e <= n; e++) {
      if (ocnt[e] > 0) {
        stack[e] = o;
        o = e;
      }
      else {
        for (; -ocnt[e] > 0; ocnt[e] += p) {
          if (-ocnt[e] >= ocnt[o]) p = ocnt[o];
          else p = -ocnt[e];

          //printf ("p=%d\n", p);
          result = (result + 1000002013 - 
            (e-o)*(long long)(n+n-e+o+1)/2%1000002013
            * (long long) p %1000002013)%1000002013;
          //printf ("Expense=%d %d,%d,%d,%d\n", (e-o)*(n+n-e+o+1)/2,n,e,o,p);
          if (-ocnt[e] >= ocnt[o]) o = stack[o];
          else ocnt[o] -= p;
        }
      }
    }
    printf ("Case #%d: %d\n", i, result);
  }
  return 0;
}