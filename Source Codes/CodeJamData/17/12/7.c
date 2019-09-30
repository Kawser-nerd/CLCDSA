#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

int ans, N, P, R[50], g[50][50];
char u[50][50];

void f(int i, int l, int h, int cur) {
  if(DEBUG)
    printf("f(i = %d, l = %d, h = %d, cur = %d), ans = %d\n", i, l, h, cur, ans);

  if(i >= N) {
    cur++;
    ans = max(ans, cur);
    if(DEBUG)
      printf("cur = %d, ans = %d\n", cur, ans);
    if(ans >= P)
      return;
    f(0, 0, INT_MAX, cur);
    return;
  }
  for(int j = 0; j < P; j++)
    if(!u[i][j]) {
      if(DEBUG)
	printf("l2: i = %d, R[i] = %d\n", i, R[i]);
      int l2 = g[i][j] / R[i];
      for(; R[i] * l2 * 11 >= g[i][j] * 10; l2--)
	if(DEBUG)
	  printf("l2 = %d\n", l2);
      l2++;
      if(DEBUG)
	printf("i = %d, j = %d, l = %d, h = %d, cur = %d, l2 = %d\n", i, j, l, h, cur, l2);
      if(R[i] * l2 * 11 >= g[i][j] * 10 && R[i] * l2 * 9 <= g[i][j] * 10 && l2 <= h) {
	if(DEBUG)
	  printf("h2: i = %d, R[i] = %d\n", i, R[i]);
	int h2 = g[i][j] / R[i];
	for(; R[i] * h2 * 9 <= g[i][j] * 10; h2++)
	  if(DEBUG)
	    printf("h2 = %d\n", h2);
	h2--;
	if(DEBUG)
	  printf("i = %d, j = %d, l = %d, h = %d, cur = %d, l2 = %d, h2 = %d\n", i, j, l, h, cur, l2, h2);
	if(R[i] * h2 * 11 >= g[i][j] * 10 && R[i] * h2 * 9 <= g[i][j] * 10 && h2 >= l && h2 >= l2) {
	  u[i][j] = 1;
	  f(i + 1, max(l2, l), min(h2, h), cur);
	  if(ans >= P)
	    return;
	  u[i][j] = 0;
	}
      }
    }
}

int main() {
  int tc, cn, i, j;
  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%d%d", &N, &P);
    for(i = 0; i < N; i++)
      scanf("%d", &R[i]);
    for(i = 0; i < N; i++)
      for(j = 0; j < P; j++)
	scanf("%d", &g[i][j]);
    ans = 0;
    memset(u, 0, sizeof(u));
    f(0, 0, INT_MAX, 0);
    printf("Case #%d: %d\n", cn, ans);
  }
}
