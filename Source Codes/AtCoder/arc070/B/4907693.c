#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<assert.h>

typedef uint64_t bitset_val;

typedef struct bitSetBy64bit{
  uint64_t *array;
  size_t array_len;
  size_t num;
} bitset;

bitset* new_bitset (const size_t num) {
  bitset *b = (bitset *) calloc (1, sizeof (bitset));
  b->num = num;
  b->array_len = (num + sizeof (uint64_t) - 1) / sizeof (uint64_t);
  b->array = (uint64_t *) calloc (b->array_len, sizeof (uint64_t));
  return b;
}

void free_bitset (bitset * const b) {
  free (b->array);
  free (b);
}

static inline void fix_bitset (bitset * const b) {
  if (b->num % sizeof (uint64_t) != 0) {
    b->array[b->array_len - 1] &= ((uint64_t)1 << (b->num % sizeof (uint64_t))) - 1;
  }
}

void set_bitset (bitset * const b) {
  const uint64_t t = ~(uint64_t)0;
  for (size_t i = 0; i < b->array_len; ++i) {
    b->array[i] = t;
  }
  fix_bitset (b);
}

void clear_bitset (bitset * const b) {
  const uint64_t t = 0;
  for (size_t i = 0; i < b->array_len; ++i) {
    b->array[i] = t;
  }
}

void flip_bitset (bitset * const b) {
  for (size_t i = 0; i < b->array_len; ++i) {
    b->array[i] = ~b->array[i];
  }
  fix_bitset (b);
}

inline int getAt_bitset (const bitset *b, const size_t index) {
  assert (0 <= index && index < b->num);
  return (b->array[index / sizeof (uint64_t)] >> (index % sizeof (uint64_t))) & 1;
}

inline void setAt_bitset (bitset *const b, const size_t index) {
  assert (0 <= index && index < b->num);
  b->array[index / sizeof (uint64_t)] |= (uint64_t)1 << (index % sizeof (uint64_t));
}

inline void clearAt_bitset (bitset * const b, const size_t index) {
  assert (0 <= index && index < b->num);
  b->array[index / sizeof (uint64_t)] &= ~((uint64_t)1 << (index % sizeof (uint64_t)));
}

inline void flipAt_bitset (bitset * const b, const size_t index) {
  assert (0 <= index && index < b->num);
  b->array[index / sizeof (uint64_t)] ^= (uint64_t)1 << (index % sizeof (uint64_t));
}

void assign_bitset (bitset * const x, const bitset * const a) {
  assert (x->num >= a->num);
  size_t i;
  for (i = 0; i < a->array_len; ++i) {
    x->array[i] = a->array[i];
  }
  for (; i < x->array_len; ++i) {
    x->array[i] = 0;
  }
}

void left_shift_bitset (bitset * const x, const bitset * const a, const size_t shift) {
  clear_bitset (x);
  size_t p = shift / sizeof (uint64_t);
  size_t q = shift % sizeof (uint64_t);
  if (q == 0) {
    for (size_t i = 0; i + p < x->array_len && i < a->array_len; ++i) {
      x->array[i + p] = a->array[i];
    }
  } else {
    size_t i;
    for (i = 0; i + p + 1 < x->array_len && i + p < a->array_len; ++i) {
      uint64_t v = a->array[i];
      x->array[i + p] |= v << q;
      x->array[i + p + 1] |= v >> (sizeof (uint64_t) - q);
    }
    if (i < a->array_len && i + p < x->array_len) {
      x->array[i + p] |= a->array[i] << q;
    }
  }
  fix_bitset (x);
}

typedef uint32_t u32;

void trans (bitset * const b, const u32 a) {
  static bitset *tmp = NULL;
  if (tmp == NULL) tmp = new_bitset (b->num);
  left_shift_bitset (tmp, b, a);
  for (size_t i = 0; i < b->array_len; ++i) {
    b->array[i] |= tmp->array[i];
  }
}

u32 calc (const u32 *a, const u32 n, const u32 k, bitset * const b) {
  if (n == 1) {
    if (a[0] >= k) return 0;
    for (u32 i = k - 1; i >= k - a[0]; --i) {
      if (getAt_bitset (b, i)) {
	return 0;
      }
    }
    return 1;
  }
  bitset *save = new_bitset (k);
  assign_bitset (save, b);
  u32 m = n / 2;
  for (u32 i = 0; i < m; ++i) {
    trans (b, a[i]);
  }
  u32 ans = calc (a + m, n - m, k, b);
  assign_bitset (b, save);
  free_bitset (save);
  for (u32 i = m; i < n; ++i) {
    trans (b, a[i]);
  }
  return ans + calc (a, m, k, b);
}

void run (void) {
  u32 n, k;
  scanf ("%" SCNu32 "%" SCNu32, &n, &k);
  u32 *a = (u32 *) calloc (n, sizeof (u32));
  for (u32 i = 0; i < n; ++i) {
    scanf ("%" SCNu32, a + i);
  }
  bitset *b = new_bitset (k);
  setAt_bitset (b, 0);
  u32 ans = calc (a, n, k, b);
  printf ("%" PRIu32 "\n", ans);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:147:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNu32 "%" SCNu32, &n, &k);
   ^
./Main.c:150:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNu32, a + i);
     ^