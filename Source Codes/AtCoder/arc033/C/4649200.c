#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

void add (i32 *bit, i32 index, i32 val) {
  const i32 n = bit[0];
  for (i32 i = index; i <= n; i += i & -i) {
    bit[i] += val;
  }
}

i32 search (const i32 *bit, i32 x) {
  const i32 n = bit[0];
  i32 k = 1;
  while ((2 * k) <= n) k *= 2;
  i32 w = 0;
  for (; k > 0; k >>= 1) {
    if (k + w <= n && bit[k + w] < x) {
      x -= bit[w + k];
      w += k;
    }
  }
  return w + 1;
}

void run (void) {
  i32 q;
  scanf ("%" SCNi32, &q);
  const i32 m = 200000;
  i32 *bit = (i32 *) calloc (m + 1, sizeof (i32));
  bit[0] = m;
  while (q--) {
    i32 t, x;
    scanf("%" SCNi32 "%" SCNi32, &t, &x);
    if (t == 1) {
      add (bit, x, 1);
    } else {
      i32 v = search (bit, x);
      add (bit, v, -1);
      printf ("%" PRIi32 "\n", v);
    }
  }
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &q);
   ^
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%" SCNi32 "%" SCNi32, &t, &x);
     ^