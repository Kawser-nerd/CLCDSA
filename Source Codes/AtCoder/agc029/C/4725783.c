#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

typedef struct node {
  i32 number;
  i32 len;
} node;

int can (const i32 m, const i32 *a, const i32 n) {
  static node *stack = NULL;
  if (stack == NULL) {
    stack = (node *) calloc (n, sizeof (node));
  }
  stack[0] = (node) {1, a[0]};
  i32 top = 1;
  i32 sum = a[0];
  for (i32 i = 1; i < n; ++i) {
    if (a[i] > sum) {
      stack[top++] = (node) {1, a[i] - sum};
      sum = a[i];
      continue;
    }
    node t = stack[--top];
    sum -= t.len;
    while (sum >= a[i]) {
      t = stack[--top];
      sum -= t.len;
    }
    while (top > 0 && t.number == m) {
      t = stack[--top];
      sum -= t.len;
    }
    if (t.number == m) return 0;
    if (sum + t.len > a[i]) {
      t.len = a[i] - sum;
    }
    t.len--;
    if (t.len > 0) {
      stack[top++] = t;
      sum += t.len;
    }
    stack[top++] = (node) {t.number + 1, 1};
    sum++;
    if (a[i] > sum) {
      stack[top++] = (node) {1, a[i] - sum};
      sum = a[i];
    }
  }
  return 1;
}

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    scanf ("%" SCNi32, a + i);
  }
  i32 l = 0;
  i32 r = n;
  while (r - l > 1) {
    i32 m = (l + r) / 2;
    if (can (m, a, n)) {
      r = m;
    } else {
      l = m;
    }
  }
  printf ("%" PRIi32 "\n", r);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:58:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &n);
   ^
./Main.c:61:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32, a + i);
     ^