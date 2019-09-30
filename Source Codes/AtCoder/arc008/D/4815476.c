#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef struct segment_tree_void {
  void *array;
  int32_t size;
  size_t val_size;
  void (*func) (void *, const void *, const void *);
} segment_tree;

static inline void segment_tree_memcpy (void *dst, const void *src, size_t size) {
  uint8_t *p = dst;
  const uint8_t *q = src;
  while (size--) {
    *p++ = *q++;
  }
}

segment_tree* new_segment_tree (const void *ini, const int32_t n, const size_t val_size, void (*func) (void *, const void *, const void *)) {
  int32_t k = 1;
  while (k < n) k *= 2;
  segment_tree *s = (segment_tree *) calloc (1, sizeof (segment_tree));
  s->array = calloc (2 * k, val_size);
  s->size = k;
  s->val_size = val_size;
  s->func = func;
  for (int32_t i = k; i < 2 * k; ++i) {
    segment_tree_memcpy ((uint8_t *)s->array + i * val_size, ini, val_size);
  }
  uint8_t *a = s->array;
  for (int32_t i = k - 1; i > 0; --i) {
    func (a + i * val_size, a + (2 * i) * val_size, a + (2 * i + 1) * val_size);
  }
  return s;
}

void update (segment_tree * const s, int32_t k, const void *val) {
  k += s->size;
  uint8_t *p = s->array;
  const size_t size = s->val_size;
  segment_tree_memcpy (p + k * size, val, size);
  for (k >>= 1; k > 0; k >>= 1) {
    s->func (p + k * size, p + 2 * k * size, p + (2 * k + 1) * size);
  }
}

void find (const segment_tree *s, int32_t l, int32_t r, void *res) {
  int32_t lindex[64];
  int32_t rindex[32];
  int32_t llen = 0;
  int32_t rlen = 0;
  for (l += s->size, r += s->size; l < r; l >>= 1, r >>= 1) {
    if (l & 1) lindex[llen++] = l++;
    if (r & 1) rindex[rlen++] = --r;
  }
  while (rlen > 0) {
    lindex[llen++] = rindex[--rlen];
  }
  const uint8_t *p = s->array;
  segment_tree_memcpy (res, p + lindex[0] * s->val_size, s->val_size);
  for (int32_t i = 1; i < llen; ++i) {
    s->func (res, res, p + lindex[i] * s->val_size);
  }
}

typedef int32_t i32;
typedef int64_t i64;

typedef struct oishikunaru {
  double a,b;
} node;

void func (void *c, const void *a, const void *b) {
  node *p = (node *)a;
  node *q = (node *)b;
  *(node *)c = (node) {p->a * q->a, p->b * q->a + q->b};
}

int cmp (const void *a, const void *b) {
  i64 p = *(i64 *)a;
  i64 q = *(i64 *)b;
  return p == q ? 0 : p < q ? -1 : 1;
}

i32 to_index (const i64 *z, const i32 len, const i64 v) {
  i32 l = 0;
  i32 r = len;
  while (r - l > 1) {
    i32 m = (l + r) / 2;
    if (v == z[m]) return m;
    if (v < z[m]) {
      r = m;
    } else {
      l = m;
    }
  }
  return l;
}

void run (void) {
  i64 n;
  i32 m;
  scanf ("%" SCNi64 "%" SCNi32, &n, &m);
  i64 *p = (i64 *) calloc (m, sizeof (i64));
  double *a = (double *) calloc (m, sizeof (double));
  double *b = (double *) calloc (m, sizeof (double));
  i64 *z = (i64 *) calloc (m, sizeof (i64));
  for (i32 i = 0; i < m; ++i) {
    scanf ("%" SCNi64 "%lf%lf", p + i, a + i, b + i);
    z[i] = p[i];
  }
  qsort (z, m, sizeof (i64), cmp);
  i32 len = 1;
  for (i32 i = 1; i < m; ++i) {
    if (z[i] == z[len - 1]) continue;
    z[len++] = z[i];
  }
  node ini = {1, 0};
  segment_tree *s = new_segment_tree (&ini, len, sizeof (node), func);
  double min = 1;
  double max = 1;
  for (i32 i = 0; i < m; ++i) {
    update (s, to_index (z, len, p[i]), &((node){a[i], b[i]}));
    node t;
    find (s, 0, len, &t);
    double v = t.a + t.b;
    if (min > v) min = v;
    if (max < v) max = v;
  }
  printf ("%.7f\n%.7f\n", min, max);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:105:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi64 "%" SCNi32, &n, &m);
   ^
./Main.c:111:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi64 "%lf%lf", p + i, a + i, b + i);
     ^