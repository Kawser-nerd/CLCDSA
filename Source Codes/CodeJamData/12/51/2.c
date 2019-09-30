#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int L, P, idx;
} game;

int cmp(const void *aa, const void *bb)
{
  const game *a = (const game*)aa;
  const game *b = (const game*)bb;
  if (b->P*a->L != a->P*b->L)
    return b->P*a->L - a->P*b->L;
  else
    return a->idx - b->idx;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    int N;
    scanf("%d", &N);
    game g[N];
    for (int i=0; i<N; i++)
      g[i].idx = i;
    for (int i=0; i<N; i++)
      scanf("%d", &g[i].L);
    for (int i=0; i<N; i++)
      scanf("%d", &g[i].P);
    qsort(g, N, sizeof(game), cmp);
    printf("Case #%d:", t);
    for (int i=0; i<N; i++)
      printf(" %d", g[i].idx);
    printf("\n");
  }
  return 0;
}
