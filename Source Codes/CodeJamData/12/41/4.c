#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a>b?a:b; };
int min(int a, int b) { return a<b?a:b; };

int main()
{
  int T;
  scanf("%d", &T);
  for (int t= 1 ; t <= T; t++)
  {
    int N;
    scanf("%d", &N);
    int d[N+1], l[N+1];
    for (int i=0; i<N; i++)
      scanf("%d %d", &d[i], &l[i]);
    int D;
    scanf("%d", &D);
    d[N] = D;
    l[N] = D;
    
    int best[N+1];
    memset(best, 0, sizeof(best));
    best[0] = d[0];
    best[N] = -1;
    for (int i=0; i<N; i++)
      for (int j=i+1; j <= N && d[j] - d[i] <= best[i]; j++)
        best[j] = min(max(best[j], d[j] - d[i]), l[j]);
    printf("Case #%d: %s\n", t, best[N] >= 0 ? "YES" : "NO");
  }
  return 0;
}
