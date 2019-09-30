#include <stdio.h>
#include <stdlib.h>

#define ABS(a) ((a)<0 ? -(a) : (a))
#define MAX(a, b) ((a)>(b) ? (a) : (b))
#define CC 36
#define DD 28
#define NN 100

int main()
{
  int T, C, D, N;
  int i, j, k, m;
  char c1[CC], c2[CC], ct[CC];
  char d1[DD], d2[DD];
  int d1f[DD], d2f[DD];
  char n[NN];
  char s[NN];
  char buf[NN];
  int l;

  scanf("%d", &T);

  for (i = 0; i < T; i++) {
    scanf("%d", &C);
    for (j = 0; j < C; j++) {
      scanf("%s", buf);
      c1[j] = buf[0];
      c2[j] = buf[1];
      ct[j] = buf[2];
    }
    scanf("%d", &D);
    for (j = 0; j < D; j++) {
      scanf("%s", buf);
      d1[j] = buf[0];
      d2[j] = buf[1];
      d1f[j] = d2f[j] = -1;
    }
    scanf("%d", &N);
    scanf("%s", n);

    for (k = 0; k < N; k++) {
      for (j = 0; j < C; j++) {
	if (k >= 1 && (c1[j] == n[k] && c2[j] == n[k-1]) ||
	    (c2[j] == n[k] && c1[j] == n[k-1])) {
	  n[k-1] = ' ';
	  n[k] = ct[j];
	  //c1[j] = c2[j] = '*';
	}
      }
      for (j = 0; j < D; j++) {
	if (d1f[j] >= 0 && n[d1f[j]] != d1[j]) d1f[j] = -1;
	if (d2f[j] >= 0 && n[d2f[j]] != d2[j]) d2f[j] = -1;

	if (d1[j] == n[k] && d2f[j] >= 0) {
	  for (m = 0; m <= k; m++) {
	    n[m] = ' ';
	  }
	  d1f[j] = d2f[j] = -1;
	} else if (d2[j] == n[k] && d1f[j] >= 0) {
	  for (m = 0; m <= k; m++) {
	    n[m] = ' ';
	  }
	  d1f[j] = d2f[j] = -1;
	} else if (d1[j] == n[k] && d1f[j] == -1) {
	  d1f[j] = k;
	} else if (d2[j] == n[k] && d2f[j] == -1) {
	  d2f[j] = k;
	}
      }
    }

    l = 0;
    for (k = 0; k < N; k++)
      if (n[k] != ' ')
	s[l++] = n[k];

    printf("Case #%d: [", i+1);
    for (j = 0; j < l - 1; j++) {
      printf("%c, ", s[j]);
    }
    if (l > 0)
      printf("%c]\n", s[l - 1]);
    else
      printf("]\n");
  }

  return 0;
}
