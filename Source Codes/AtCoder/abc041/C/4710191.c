// https://atcoder.jp/contests/abc041/tasks/abc041_c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int i;
  int h;
} Data;
Data data[100000];

int compare(const void *a, const void *b) {
    return ((Data *)b)->h - ((Data *)a)->h;
}

void solv(int n) {
    int i;

    for (i = 0; i < n; i++) {
      data[i].i = i + 1;
      scanf("%d", &data[i].h);
    }
    qsort(data, n, sizeof (Data), compare);

    for (i = 0; i < n; i++) {
      printf("%d\n", data[i].i);
    }
}

int main(int argc, char **argv) {
  int n;

  while (scanf("%d", &n) != EOF) {
    solv(n);
  }

  return 0;
} ./Main.c: In function ‘solv’:
./Main.c:20:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &data[i].h);
       ^