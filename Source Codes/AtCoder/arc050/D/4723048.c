#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NMAX 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int len, len2, part, sentinels, rank[NMAX+1], sa[NMAX+1], lcp[NMAX+1], dat[(1<<19)-1];
int compare_sa(const void *a, const void *b);
int compare_res(const void *a, const void *b);
void construct_sa(char *string, int n);
void construct_lcp(char *string, int n);
int rmq_init(int n);
int minimize(int a, int b, int k, int l, int r);
int main(void)
{
  int i, n, res[NMAX];
  char s[NMAX+1];
  scanf("%d%*c", &n);
  scanf("%s%*c", s);
  construct_sa(s, n);
  construct_lcp(s, n);
  sentinels = n;
  lcp[n] = n;
  len2 = rmq_init(n);
  for (i = 0; i < n; i++) res[i] = i;
  qsort(res, n, sizeof(int), compare_res);
  for (i = 0; i < n; i++) printf("%d\n", res[i] + 1);
}

int compare_sa(const void *a, const void *b)
{
  int i = *(int*)a, j = *(int*)b;
  if (rank[i] != rank[j]) return rank[i] - rank[j];
  else {
    int ri = (i + part <= len ? rank[i+part] : -1), rj = (j + part <= len ? rank[j+part] : -1);
    return ri - rj;
  }
}

int compare_res(const void *a, const void *b)
{
  int i = *(int*)a, j = *(int*)b, minij = min(i, j), maxij = max(i, j), rminij = min(rank[i], rank[j]), rmaxij = max(rank[i], rank[j]);
  int toggle = (i > j ? -1 : 1);
  if (minimize(rminij, rmaxij, 0, 0, len2) < len - maxij) return rank[i] - rank[j];
  else if (minimize(min(rank[minij], rank[len - (maxij - minij)]), max(rank[minij], rank[len - (maxij - minij)]), 0, 0, len2) < maxij - minij) return toggle * (rank[len-(maxij-minij)] - rank[minij]);
  else return 0;
}

void construct_sa(char *string, int n)
{
  int i, tmp[NMAX+1];
  len = n;
  for (i = 0; i < len; i++) {
    sa[i] = i;
    rank[i] = string[i];
  }
  sa[len] = len;
  rank[len] = -1;
  for (part = 1; part <= len; part *= 2) {
    qsort(sa, len + 1, sizeof(int), compare_sa);
    tmp[sa[0]] = 0;
    for (i = 1; i <= len; i++) {
      tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(&sa[i-1], &sa[i]) ? 1 : 0);
    }
    for (i = 0; i <= len; i++) rank[i] = tmp[i];
  }
}

void construct_lcp(char *string, int n)
{
  int i, h = 0;
  for (i = 0; i <= n; i++) rank[sa[i]] = i;
  lcp[0] = 0;
  for (i = 0; i < n; i++) {
    int j = sa[rank[i] - 1];
    if (h > 0) h--;
    while (j + h < n && i + h < n) {
      if (string[j+h] != string[i+h]) break;
      h++;
    }
    lcp[rank[i]-1] = h;
  }
}

int rmq_init(int n)
{
  int i, sz, n2 = 1;
  while (n2 < n) n2 *= 2;
  for (i = 0; i < 2 * n2 - 1; i++) dat[i] = lcp[sentinels];
  for (i = 0; i < n; i++) dat[i+n2-1] = lcp[i];
  sz = n2;
  n2--;
  while (n2-- > 0) {
    if (dat[n2*2+1] < dat[n2*2+2]) dat[n2] = dat[n2*2+1];
    else dat[n2] = dat[n2*2+2];
  }
  return sz;
}

int minimize(int a, int b, int k, int l, int r)
{
  if (a >= r || b <= l) return lcp[sentinels];
  else if (a <= l && b >= r) return dat[k];
  else {
    int vl , vr;
    vl = minimize(a, b, k * 2 + 1, l, (l + r) / 2);
    vr = minimize(a, b, k * 2 + 2 , (l + r) / 2, r);
    if (vl < vr) return vl;
    else return vr;
  }
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%*c", &n);
   ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%*c", s);
   ^