#include <stdio.h>

static int T;
static int vals[128];
static int resp[128];
static int test[128];
static int invtest[128];

void order (void)
{
  int i, j, temp;
  for (i = T-1; i >= 0; i--)
    for (j = 0; j < i; j++) {
      if (vals[j] > vals[j + 1]) {
        temp = vals[j];
        vals[j] = vals[j + 1];
        vals[j + 1] = temp;

        temp = test[j];
        test[j] = test[j + 1];
        test[j + 1] = temp;

        invtest[test[j]] = j;
        invtest[test[j+1]] = j+1;
      }
    }
}

void calcula (void) {
  register int a = 2, b = 6, c;
  int i, j = 1;
  for (i = 0; i < T; i++) {
    while (j != vals[i]) {
      c = a;
      a = b;
      b = 6 * a - 4 * c + 4000;
      b %= 1000;
      j++;
    }
    resp[i] = b;
  }
}

int main (int argc, char **argv)
{
  int t;
  scanf ("%d", &T);
  for (t = 1; t <= T; t++) {
    scanf ("%d", &vals[t-1]);
    test[t-1] = t-1;
    invtest[t - 1] = t-1;
  }
  order ();
  calcula ();
  for (t = 1; t <= T; t++) {
    int v = resp[invtest[t-1]];
    if (v == 0) v = 999;
    else v--;
    printf ("Case #%d: %03d\n", t, v);
  }

  return 0;
}
