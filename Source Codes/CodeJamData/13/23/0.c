#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

struct vertex {
  int flags;
  int child[26];
};

struct vertex *ver[100000000];
char s[10000];
int r[10000][6];
int *rr;
int n;

int count (struct vertex *v, int p, int t, int dif) {
  if (t > 4) { t = 4; }
  if (v->flags) { 
    if (r[p][t] >= dif) {
      r[p][t] = dif;
    }
  }
  if (p == n) { return 0; }
  int q = s[p] - 'a';
  int e = v->child[q];
  if (e >= 0) {
    count (ver[e], p + 1, t + 1, dif);
  }
  if (t == 4) {
    int i;
    for (i = 0; i < 26; i++) if (i != q) {
      int e = v->child[i];
      if (e >= 0) {
        count (ver[e], p + 1, 0, dif + 1);
      }
    }
  }
  return 0;
}

void solve (void) {
  assert (scanf ("%s\n", s) == 1);
  int i, j;
  n = strlen (s);
  for (i = 0; i <= 5; i++) {
    r[0][i] = 0;
  }
  for (i = 1; i <= n; i++)
    for (j = 0; j <= 5; j++)
      r[i][j] = n;

  for (i = 0; i < n; i++) 
    for (j = 0; j <= 4; j++) {
      if (j == 4 || r[i][j] < r[i][j + 1]) {
        count (ver[1], i, j, r[i][j]);
      }
      //assert (r[i][0] < n || r[i][1] < n || r[i][2] < n || r[i][3] < n || r[i][4] < n);
    }
  
  int best = n;
  for (i = 0; i <= 5; i++)
    if (r[n][i] < best) {
      best = r[n][i];
    }
  printf ("%d\n", best);
}

int vn = 1;
int alloc_vertex (void) {
  struct vertex *v = malloc (sizeof (*v));
  v->flags = 0;
  int i;
  for (i = 0; i < 26; i++)
    v->child[i] = -1;
  assert (vn < 100000000);
  ver[vn ++] = v;
  return vn - 1;
}

void add (struct vertex *v, char *s) {
  if (!*s) { 
    v->flags |= 1;
    return; 
  }
  int i = (*s) - 'a';
  if (v->child[i] == -1) {
    v->child[i] = alloc_vertex ();
  }
  add (ver[v->child[i]], s + 1);
}

int main () {
  FILE *f = fopen ("/home/vvaltman/Downloads/garbled_email_dictionary.txt", "rt");
  assert (alloc_vertex () == 1);
  while (fscanf (f, "%s\n", s) >= 1) {
    add (ver[1], s);
  }

  int _;
  assert (scanf ("%d\n", &_) > 0);
  int __;
  for (__ = 0; __ < _; __++) {
    printf ("Case #%d: ", __ + 1);
    solve ();
  }
  return 0;
}
