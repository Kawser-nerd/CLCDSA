#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

#ifdef ONLINE_JUDGE
static char _in_buf[100000], *_in_p1 = _in_buf, *_in_p2 = _in_buf;
#define getchar() (_in_p1 == _in_p2 && (_in_p2 = (_in_p1 = _in_buf) + fread(_in_buf, 1, 100000, stdin), _in_p1 == _in_p2) ? EOF : *_in_p1 ++)
#endif
#ifdef __cplusplus
extern "C" {
#endif
__attribute__((always_inline)) __inline__
void read(int *now) {
  int f = *now = 0; register char c = getchar();
  while ((c > 57 || c < 48) && ~c && c != '-') c = getchar();
  (c == '-') && ((f = 1), c = getchar());
  for (; c > 47 && c < 58; *now = (*now << 3) + (*now << 1) + c - '0', c = getchar());
  f && (*now = -*now);
}
#ifdef __cplusplus
}
#endif

#define N 262144
#define inf 0x3f3f3f3f

int n, x, y, l, r, p[N];
int tr[N << 1 | 5], tr1[N << 1 | 5], tr2[N << 1 | 5];
#define build(tr) for (i = N; -- i; ) \
                   tr[i] = min(tr[i << 1], tr[i << 1 | 1])
#ifdef __cplusplus
extern "C" {
#endif
__attribute__((always_inline)) __inline__
int query(int *t, int l, int r) {
  int res = inf; l += N - 1, r += N + 1;
  for (; l ^ r ^ 1; l >>= 1, r >>= 1)
    (~l & 1) && (res = min(res, t[l + 1])), 
    (r & 1) && (res = min(res, t[r - 1]));
  return res;
}
#ifdef __cplusplus
}
#endif

struct node {
  int a, b, c, d;
} tp, q[N];
int sz = 0;
#ifdef __cplusplus
extern "C" {
#endif
__attribute__((always_inline)) __inline__
int cmp(struct node a, struct node b) {
  if (a.a ^ b.a) return a.a - b.a;
  if (a.b ^ b.b) return a.b - b.b;
  if (a.c ^ b.c) return a.c - b.c;
  return a.d - b.d;
}
__attribute__((always_inline)) __inline__
void swap(struct node *a, struct node *b) { struct node c = *a; *a = *b; *b = c; }
__attribute__((always_inline)) __inline__
void heap_push(struct node x) {
  q[++ sz] = x;
  for (int i = sz, j = i >> 1; j; i = j, j >>= 1)
    if (cmp(q[j], q[i]) > 0) swap(q + i, q + j);
}
__attribute__((always_inline)) __inline__
void heap_pop() {
  q[1] = q[sz --];
  for (int i = 1, j = i << 1; j <= sz; i = j, j <<= 1) {
    ((j | 1) <= sz && cmp(q[j | 1], q[j]) < 0) && (j |= 1);
    if (cmp(q[i], q[j]) > 0) swap(q + i, q + j);
    else break;
  }
}
__attribute__((always_inline)) __inline__
void push(int l, int r) {
  if (l > r) return; int x = query(l & 1 ? tr1 : tr2, l, r);
  heap_push((struct node){x, query(l & 1 ? tr2 : tr1, p[x] + 1, r), l, r});
}
#ifdef __cplusplus
}
#endif

int main() {
  register int i;
  for (read(&n), i = 1; i <= n; ++ i)
    read(&x), p[x] = i, tr[i + N] = x, 
    tr1[i + N] = i & 1 ? x : inf, tr2[i + N] = i & 1 ? inf : x;
  build(tr); build(tr1); build(tr2);
  for (push(1, n); sz; ) {
    x = q[1].a, y = q[1].b, l = q[1].c, r = q[1].d;
    printf("%d %d ", x, y), heap_pop();
    push(l, p[x] - 1), push(p[x] + 1, p[y] - 1), push(p[y] + 1, r);
  }
  putchar('\n');
}