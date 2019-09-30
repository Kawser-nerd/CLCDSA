#include <stdio.h>

#define ML 4096
static char buf[ML];
static int d[21];
static int f[21];

void sort(int a, int b)
{
  int i, j, t;
  for (i = a; i < b - 1; i++)
    for (j = i + 1; j < b; j++)
      if (d[i] > d[j]) {
	t = d[i];
	d[i] = d[j];
	d[j] = t;
    }
}

int main()
{
  int num, base;
  int i, t, n, z;
  int ii, li, ni, nii;
  char *cur;

  fgets(buf, ML, stdin);
  sscanf(buf, "%d", &num);

  f[0] = 1;
  for (n = 0; n < num; n++) {
    fgets(buf, ML, stdin);
    for (ii = 0; buf[ii] != '\n'; ii++) {
      i = buf[ii] - '0';
      d[ii] = i;
      if (ii > 0) f[ii] = i - d[ii-1];
      if (f[ii] > 0) li = ii;
    }

    printf("Case #%d: ", n+1);
    if (li == 0) {
      sort(0, ii);
      
      if (d[0] == 0) {
	for (i = 0, z = 0; d[i] == 0; i++) ;
	d[0] = d[i];
	d[i] = 0;
	printf("%d0", d[0]);
	for (i = 1; i < ii; i++)
	  printf("%d", d[i]);
      } else {
	printf("%d0", d[0]);
	for (i = 1; i < ii; i++)
	  printf("%d", d[i]);
      }
    } else {
      ni = d[li];
      nii = li;
      for (i = li+1; i < ii; i++)
	if (d[i] > d[li-1] && d[i] < ni) {
	  ni = d[i];
	  nii = i;
	}
      t = d[li-1];
      d[li-1] = d[nii];
      d[nii] = t;
      sort(li, ii);

      for (i = 0; i < ii; i++)
	printf("%d", d[i]);
    }

    printf("\n");
  }

  return 0;
}
