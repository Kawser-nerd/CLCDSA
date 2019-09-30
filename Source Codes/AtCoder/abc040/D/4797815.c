// https://atcoder.jp/contests/abc040/tasks/abc040_d
#include <stdio.h>
#include <stdlib.h>

int par[100000];

void init(int n) {
  int i;
  for (i = 0; i < n; i++) {
    par[i] = -1;
  }
}

int root(int x) {
  if (par[x] < 0) {
    return x;
  } else {
    return par[x] = root(par[x]);
  }
}

int same(int x, int y) {
  return root(x) == root(y);
}

void unite(int x, int y) {
  int t;
  x = root(x);
  y = root(y);
  if (x == y) {
    return;
  }
  if (par[y] < par[x]) {
    t = y;
    y = x;
    x = t;
  }
  par[x] += par[y];
  par[y] = x;
}

int size(x) {
  return -par[root(x)];
}

typedef struct {
  int i, v, w, size;
} Q;

int compare_qi(const void *a, const void *b) {
    return ((Q *)a)->i - ((Q *)b)->i;
}

int compare_qw(const void *a, const void *b) {
    return ((Q *)b)->w - ((Q *)a)->w;
}

typedef struct {
  int a, b, y;
} D;

int compare_dy(const void *a, const void *b) {
    return ((D *)b)->y - ((D *)a)->y;
}

int main(int argc, char **argv) {
  int i, j, n, m, q;
  D d[200000];
  Q qq[100000];

  while (scanf("%d %d", &n, &m) != EOF) {
    for (i = 0; i < m; i++) {
      scanf("%d %d %d", &d[i].a, &d[i].b, &d[i].y);
      d[i].a--;
      d[i].b--;
    }
    qsort(d, m, sizeof (D), compare_dy);

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
      scanf("%d %d", &qq[i].v, &qq[i].w);
      qq[i].i = i;
      qq[i].v--;
    }
    qsort(qq, q, sizeof (Q), compare_qw);

    init(n);
    j = 0;
    for (i = 0; i < q; i++) {
      for (; d[j].y > qq[i].w; j++) {
        unite(d[j].a, d[j].b);
      }
      qq[i].size = size(qq[i].v);
    }

    qsort(qq, q, sizeof (Q), compare_qi);
    for (i = 0; i < q; i++) {
      printf("%d\n", qq[i].size);
    }
  }

  return 0;
} ./Main.c: In function ‘size’:
./Main.c:42:5: warning: type of ‘x’ defaults to ‘int’ [-Wimplicit-int]
 int size(x) {
     ^
./Main.c: In function ‘main’:
./Main.c:73:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d %d %d", &d[i].a, &d[i].b, &d[i].y);
       ^
./Main.c:79:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &q);
     ^
./Main.c:81:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d %d", &qq[i].v, &qq[i].w);
       ^