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

typedef struct index_val {
  i32 index;
  i32 val;
} node;

void func (void *c, const void *a, const void *b) {
  node *p = (node *)a;
  node *q = (node *)b;
  *(node *)c = p->val < q->val ? *p : *q;
}

typedef struct range {
  i32 l, r;
} range;

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  const node ini = {0, n + 1};
  segment_tree *s = new_segment_tree (&ini, n, sizeof (node), func);
  for (i32 i = 0; i < n; ++i) {
    i32 a;
    scanf ("%" SCNi32, &a);
    update (s, i, &((node){i, a}));
  }
  range stack[32];
  i32 top = 0;
  stack[top++] = (range) {0, n};
  i64 ans = 0;
  while (top > 0) {
    range t = stack[--top];
    if (t.r <= t.l) continue;
    node v;
    find (s, t.l, t.r, &v);
    i32 k = v.index;
    ans += (i64) (k - t.l + 1) * (t.r - k) * v.val;
    if (k - t.l <= t.r - k) {
      stack[top++] = (range) {k + 1, t.r};
      stack[top++] = (range) {t.l, k};
    } else {
      stack[top++] = (range) {t.l, k};
      stack[top++] = (range) {k + 1, t.r};
    }
  }
  printf ("%" PRIi64 "\n", ans);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:88:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &n);
   ^
./Main.c:93:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32, &a);
     ^