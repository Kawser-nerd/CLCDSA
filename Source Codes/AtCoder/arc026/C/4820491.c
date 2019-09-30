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

typedef struct pair {
  i32 r, c;
} pair;

void min (void *c, const void *a, const void *b) {
  i64 p = *(i64 *)a;
  i64 q = *(i64 *)b;
  *(i64 *)c = p < q ? p : q;
}

void run (void) {
  i32 n, l;
  scanf ("%" SCNi32 "%" SCNi32, &n, &l);
  pair **p = (pair **) calloc (l, sizeof (pair *));
  i32 *len = (i32 *) calloc (l, sizeof (i32));
  i32 *max_len = (i32 *) calloc (l, sizeof (i32));
  while (n--) {
    i32 k, r, c;
    scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32, &k, &r, &c);
    if (len[k] == max_len[k]) {
      max_len[k] = 2 * max_len[k] + 1;
      p[k] = (pair *) realloc (p[k], sizeof (pair) * max_len[k]);
    }
    p[k][len[k]++] = (pair) {r, c};
  }
  free (max_len);
  const i64 ini = (i64) 100000 * l;
  segment_tree *s = new_segment_tree (&ini, l + 1, sizeof (i64), min);
  i64 zero = 0;
  update (s, 0, &zero);
  for (i32 i = 0; i < l; ++i) {
    pair *a = p[i];
    for (i32 j = 0; j < len[i]; ++j) {
      i64 v;
      find (s, i, a[j].r + 1, &v);
      v += a[j].c;
      i64 t;
      find (s, a[j].r, a[j].r + 1, &t);
      if (t > v) {
	update (s, a[j].r, &v);
      }
    }
  }
  i64 ans;
  find (s, l, l + 1, &ans);
  printf ("%" PRIi64 "\n", ans);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:83:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32, &n, &l);
   ^
./Main.c:89:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32, &k, &r, &c);
     ^