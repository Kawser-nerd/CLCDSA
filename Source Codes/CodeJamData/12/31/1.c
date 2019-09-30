#include <stdio.h>
#include <string.h>

int a[1000][1000];
int used[1000];
int flag;
int n;

int dfs(int x)
{
  if (used[x])
    flag = 1;
  used[x] = 1;
  for (int i=0; i<n; i++)
    if (a[x][i])
      dfs(i);
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    printf("Case #%d: ", t);

    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for (int i=0; i<n; i++)
    {
      int m;
      scanf("%d", &m);
      for (int j=0; j<m; j++)
      {
        int v;
        scanf("%d", &v);
        a[i][v-1] = 1;
      }
    }
    flag = 0;
    for (int i=0; i<n; i++)
    {
      memset(used, 0, sizeof(used));
      dfs(i);
    }
    printf("%s\n", flag ? "Yes" : "No");
  }
}
