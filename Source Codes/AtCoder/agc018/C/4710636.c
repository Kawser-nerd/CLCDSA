#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef struct binaryHeap{
  void *array;
  size_t heap_size;
  size_t max_size;
  size_t val_size;
  int (*cmp) (const void *, const void *);
} heap;

heap* new_binary_heap (const size_t val_size, int (*cmpF) (const void *, const void *)) {
  heap *h = (heap *) calloc (1, sizeof (heap));
  h->array = malloc (val_size * (1 + 1));
  h->heap_size = 0;
  h->max_size = 1;
  h->val_size = val_size;
  h->cmp = cmpF;
  return h;
}

int32_t get_heap_size (const heap *h) {
  return h->heap_size;
}

int is_empty (const heap *h) {
  return h->heap_size == 0;
}

void free_heap (heap *h) {
  free (h->array);
  free (h);
}

void init_heap (heap *h) {
  h->heap_size = 0;
}

static void heap_func_swap (void * restrict a, void * restrict b, size_t val_size) {
  if ((val_size & 7) == 0) {
    uint64_t *p = (uint64_t *) a;
    uint64_t *q = (uint64_t *) b;
    val_size /= sizeof (uint64_t);
    while (val_size--) {
      uint64_t tmp = *p;
      *p++ = *q;
      *q++ = tmp;
    }
  } else {
    uint8_t *p = (uint8_t *) a;
    uint8_t *q = (uint8_t *) b;
    while (val_size--) {
      uint8_t tmp = *p;
      *p++ = *q;
      *q++ = tmp;
    }
  }
}

static void heap_func_copy (void * restrict dst, const void * restrict src, size_t val_size) {
  if ((val_size & 7) == 0) {
    uint64_t *p = (uint64_t *) src;
    uint64_t *q = (uint64_t *) dst;
    val_size /= sizeof (uint64_t);
    while (val_size--) {
      *q++ = *p++;
    }
  } else {
    uint8_t *p = (uint8_t *) src;
    uint8_t *q = (uint8_t *) dst;
    while (val_size--) {
      *q++ = *p++;
    }
  }
}

void push (heap *h, const void *val) {
  if (h->heap_size == h->max_size) {
    h->max_size = 2 * h->max_size + 1;
    h->array = realloc (h->array, h->val_size * (h->max_size + 1));
  }
  h->heap_size++;
  uint8_t *array = (uint8_t *) h->array;
  size_t k = h->heap_size;
  const size_t val_size = h->val_size;
  int (*cmp) (const void *, const void *) = h->cmp;
  heap_func_copy(array + k * val_size, val, val_size);
  while(k>1){
    size_t parent = k / 2;
    if (cmp (array + parent * val_size, array + k * val_size) <= 0) {
      return;
    }
    heap_func_swap (array + parent * val_size, array + k * val_size, val_size);
    k = parent;
  }
}

void pop (heap *h, void *res) {
  uint8_t *array = (uint8_t *) h->array;
  const size_t val_size = h->val_size;
  if (res != NULL) {
    heap_func_copy (res, array + val_size, val_size);
  }
  heap_func_copy (array + val_size, array + val_size * h->heap_size, val_size);
  h->heap_size--;
  int (* const cmp) (const void *, const void *) = h->cmp;
  const size_t n = h->heap_size;
  size_t k = 1;
  while (2 * k  + 1 <= n) {
    int c = cmp (array + val_size * 2 * k, array + val_size * (2 * k + 1));
    size_t next = 2 * k + (c <= 0 ? 0 : 1);
    if (cmp (array + val_size * k, array + val_size * next) <= 0) return;
    heap_func_swap (array + val_size * k, array + val_size * next, val_size);
    k = next;
  }
  if (2 * k <= n && cmp (array + val_size * k, array + val_size * 2 * k) > 0) {
    heap_func_swap (array + val_size * k, array + val_size * 2 * k, val_size);
  }
}

typedef int32_t i32;
typedef int64_t i64;

typedef struct node {
  i32 a, b;
} node;

int cmp_node (const void *a, const void *b) {
  const node *p = (const node *) a;
  const node *q = (const node *) b;
  i32 x = p->a - p->b;
  i32 y = q->a - q->b;
  return x == y ? 0 : x > y ? -1 : 1;
}

int cmp_int (const void *a, const void *b) {
  i32 d = *(i32 *)a - *(i32 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run (void) {
  i32 x, y, z;
  scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32, &x, &y, &z);
  const i32 n = x + y + z;
  i64 sumC = 0;
  node *p = (node *) calloc (n, sizeof (node));
  for (i32 i = 0; i < n; ++i) {
    i32 a, b, c;
    scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32, &a, &b, &c);
    sumC += c;
    p[i] = (node) {a - c, b - c};
  }
  qsort (p, n, sizeof (node), cmp_node);
  heap *h = new_binary_heap (sizeof (i32), cmp_int);
  i64 *front = (i64 *) calloc (z + 1, sizeof (i64));
  i64 local = 0;
  for (i32 i = 0; i < x; ++i) {
    local += p[i].a;
    push (h, &p[i].a);
  }
  front[0] = local;
  for (i32 i = x; i < x + z; ++i) {
    local += p[i].a;
    push (h, &p[i].a);
    i32 t;
    pop (h, &t);
    local -= t;
    front[i - x + 1] = local;
  }
  init_heap (h);
  local = 0;
  for (i32 i = n - 1; i >= n - y; --i) {
    local += p[i].b;
    push (h, &p[i].b);
  }
  i64 max = local + front[z];
  for (i32 i = x + z - 1; i >= x; --i) {
    local += p[i].b;
    push (h, &p[i].b);
    i32 t;
    pop (h, &t);
    local -= t;
    if (max < local + front[i - x]) {
      max = local + front[i - x];
    }
  }
  printf ("%" PRIi64 "\n", max + sumC);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:145:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32, &x, &y, &z);
   ^
./Main.c:151:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32, &a, &b, &c);
     ^