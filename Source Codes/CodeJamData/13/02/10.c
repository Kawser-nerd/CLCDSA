#include <stdio.h>
#include <stdlib.h>

void printLawn(int **lawn, int x, int y)
{
  int i, j;

  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      printf("%d ", lawn[i][j]);
    }
    printf("\n");
  }
  
  return;
}

int row(int **lawn, int x, int y, int a, int b)
{
  int j;

  for (j = 0; j < y; j++) {
    if (lawn[a][j] > lawn[a][b] && b != j) {
      return 1;
    }
  }

  return 0;
}

int col(int **lawn, int x, int y, int a, int b)
{
  int i;

  for (i = 0; i < x; i++) {
    if (lawn[i][b] > lawn[a][b] && a != i) {
      return 1;
    }
  }

  return 0;
}


int testLawn(int **lawn, int x, int y)
{
  int i, j;

  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      if (row(lawn, x, y, i, j) &&
          col(lawn, x, y, i, j))
      { return 0; }
    }
  }

  return 1;
}

int main(int argc, const char *argv[])
{
  int i, j, k;
  FILE *in = fopen("input.txt", "r");
  FILE *out = fopen("out.txt", "w");

  int cases;
  fscanf(in, "%d\n", &cases);

  int x, y;
  for (i = 0; i < cases; i++) {
    fscanf(in, "%d %d\n", &x, &y);
    int **lawn = (int **)malloc(x * sizeof(int *));
    for (j = 0; j < x; j++) {
      lawn[j] = (int *)malloc(y * sizeof(int));
    }

    for (j = 0; j < x; j++) {
      for (k = 0; k < y; k++) {
        fscanf(in, "%d", &(lawn[j][k]));
      }
    }

    int t = testLawn(lawn, x, y);
    if (t) { fprintf(out, "Case #%d: YES\n", i + 1); }
    else { fprintf(out, "Case #%d: NO\n", i + 1); }

    for (j = 0; j < x; j++) {
      free(lawn[j]);
    }
    free(lawn);
  }

  fclose(in);
  fclose(out);

  return 0;
}
