#include <stdio.h>
#include <stdlib.h>

#define INF  1000000000

int n, a, b, c;
int l[8];

int min2(int a, int b)
{
  return (a < b) ? a : b;
}

int min3(int a, int b, int c)
{
  return min2(min2(a, b), c);
}

int min4(int a, int b, int c, int d)
{
  return min2(min2(a, b), min2(c, d));
}


int dfs(int cur, int p, int q, int r)
{
  if (cur == n){
    if (min3(p, q, r) > 0)
      return abs(a - p) + abs(b - q) + abs(c - r) - 30;
    else
      return INF;
  } else {
    int ret0 = dfs(cur + 1, p, q, r);
    int ret1 = dfs(cur + 1, p + l[cur], q, r) + 10;
    int ret2 = dfs(cur + 1, p, q + l[cur], r) + 10;
    int ret3 = dfs(cur + 1, p, q, r + l[cur]) + 10;
    return min4(ret0, ret1, ret2, ret3);
  }
}

    

int main(void)
{
  scanf("%d %d %d %d", &n, &a, &b, &c);
  for (int i = 0; i < n; i++)
    scanf("%d", &l[i]);

  printf("%d\n", dfs(0,0,0,0));

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d", &n, &a, &b, &c);
   ^
./Main.c:47:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &l[i]);
     ^