#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NMAX 100000
#define LOGN 17
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define swap(a, b, type) do {type t = a; a = b; b = t;} while(0)

int len, part, sentinels, rank[NMAX+1], sa[NMAX+1], lcp[NMAX], dat[LOGN][NMAX];
int compare_sa(const void *a, const void *b);
int compare_res(const void *a, const void *b);
void construct_sa(char *string, int n);
void construct_lcp(char *string, int n);
void rmq_init(int n);
int minimize(int a, int b);
int main(void)
{
  int i, n, res[NMAX];
  char s[NMAX+1];
  scanf("%d%*c", &n);
  scanf("%s%*c", s);
  construct_sa(s, n);
  construct_lcp(s, n);
  sentinels = n;
  rmq_init(n);
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
  int i = *(int*)a, j = *(int*)b, rminij = min(rank[i], rank[j]), rmaxij = max(rank[i], rank[j]), tsign;
  if (i > j) {
    swap(i, j, int);
    tsign = -1;
  } else tsign = 1;
  if (minimize(rminij, rmaxij) < len - j) return (rank[i] - rank[j]) * tsign;
  else if (minimize(min(rank[i], rank[len - (j - i)]), max(rank[i], rank[len - (j - i)])) < j - i) {
    return (rank[len-(j-i)] - rank[i]) * tsign;
  }
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
  lcp[0] = 0;
  for (i = 0; i < n; i++) {
    int j = sa[rank[i] - 1];
    if (h > 0) h--;
    while (j + h < n && i + h < n) {
      if (string[i+h] != string[j+h]) break;
      h++;
    }
    lcp[rank[i]-1] = h;
  }
}

void rmq_init(int n)
{
  int i, j;
  for (i = 0; i< n; i++) dat[0][i] = lcp[i];
  for (i = 1; i < LOGN; i++) {
    for (j = 0; j <= n - (1 << i); j++) {
      dat[i][j] = min(dat[i-1][j], dat[i-1][j+(1<<(i-1))]);
    }
  }
}

int minimize(int a, int b)
{
  int sz = 0, tbit = 2;
  if (a == b) return sentinels;
  while ((b - a) / tbit) {
    sz++;
    tbit *= 2;
  }
  return min(dat[sz][a], dat[sz][b-(1<<sz)]);
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%*c", &n);
   ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%*c", s);
   ^