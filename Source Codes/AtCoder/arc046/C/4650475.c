#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

typedef struct person {
  i32 sortKey;
  i32 setKey;
  i32 gender;
} node;

int cmpSort (const void *a, const void *b) {
  node *p = (node *)a;
  node *q = (node *)b;
  i32 d = p->sortKey - q->sortKey;
  if (d != 0) return d < 0 ? -1 : 1;
  d = p->gender - q->gender;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

int cmpInt (const void *a, const void *b) {
  i32 d = *(i32 *)a - *(i32 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

i32 toIndex (i32 *a, i32 len, i32 v) {
  i32 l = 0;
  i32 r = len;
  while (r - l > 1) {
    i32 m = (l + r) / 2;
    if (v >= a[m]) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

void add (i32 *bit, i32 index, i32 val) {
  const i32 n = bit[0];
  for (i32 i = index; i <= n; i += i & -i) {
    bit[i] += val;
  }
}

i32 sum (i32 *bit, i32 index) {
  i32 res = 0;
  for (i32 i = index; i > 0; i -= i & -i) {
    res += bit[i];
  }
  return res;
}

i32 search (i32 *bit, i32 x) {
  const i32 n = bit[0];
  i32 k = 1;
  while (2 * k <= n) k *= 2;
  i32 w = 0;
  for (; k > 0; k >>= 1) {
    if (w + k <= n && bit[w + k] < x) {
      x -= bit[w + k];
      w += k;
    }
  }
  return w + 1;
}

void run (void) {
  i32 n, m;
  scanf ("%" SCNi32 "%" SCNi32, &n, &m);
  node *a = (node *) calloc (n + m, sizeof (node));
  i32 *z = (i32 *) calloc (n + m, sizeof (i32));
  i32 i;
  for (i = 0; i < n; ++i) {
    i32 x, y;
    scanf ("%" SCNi32 "%" SCNi32, &x, &y);
    a[i] = (node){x, y, 1};
    z[i] = y;
  }
  for (i = 0; i < m; ++i) {
    i32 x, y;
    scanf ("%" SCNi32 "%" SCNi32, &x, &y);
    a[n + i] = (node){y, x, 0};
    z[n + i] = x;
  }
  qsort (a, n + m, sizeof (node), cmpSort);
  qsort (z, n + m, sizeof (i32), cmpInt);
  i32 len = 0;
  i = 0;
  while (i < n + m) {
    z[len++] = z[i++];
    while (i < n + m && z[len - 1] == z[i]) i++;
  }
  i32 *bit = (i32 *) calloc (len + 1, sizeof (i32));
  bit[0] = len;
  i32 ans = 0;
  for (i = 0; i < n + m; ++i) {
    i32 k = toIndex (z, len, a[i].setKey) + 1;
    if (a[i].gender == 0) {
      add (bit, k, 1);
    } else {
      i32 s = sum (bit, k - 1);
      if (sum (bit, len) > s) {
	i32 index = search (bit, s + 1);
	ans++;
	add (bit, index, -1);
      }
    }
  }
  printf ("%" PRIi32 "\n", ans);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:73:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32, &n, &m);
   ^
./Main.c:79:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32 "%" SCNi32, &x, &y);
     ^
./Main.c:85:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32 "%" SCNi32, &x, &y);
     ^