#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

main()
{
  int N, M, Q;
  int *L, *R,*p,*q,*s;
  int **c,**x;
  int i, k, j;
  scanf("%d %d %d",&N,&M,&Q);

  L = (int*)malloc(sizeof (int)*M);
  R = (int*)malloc(sizeof (int)*M);
  p = (int*)malloc(sizeof (int)*Q);
  q = (int*)malloc(sizeof (int)*Q);
  s = (int*)malloc(sizeof (int)*Q);
  c = (int**)malloc(sizeof (int*)*N);
  for(i=0; i<N; i++)
    c[i] = (int*)malloc(sizeof (int)*N);
  x = (int**)malloc(sizeof (int*)*N);
  for(i=0; i<N; i++)
    x[i] = (int*)malloc(sizeof (int)*N);

  for(i=0; i<M; i++)
    scanf("%d %d",&L[i], &R[i]);
  for(i=0; i<Q; i++)
    scanf("%d %d",&p[i], &q[i]);
  for(i=0; i<N; i++)
    for(k=0; k<N; k++)
      {
        x[i][k] = 0;
        c[i][k] = 0;
      }

  for(i=0; i<M; i++)
    x[L[i]-1][R[i]-1]++;

  for(i=0; i<N; i++)
    for(j=0; j<N; j++)
      for(k=0; k<=j; k++)
        c[i][j] = c[i][j] + x[i][k];

  for(i=0; i<Q; i++)
    {
      s[i]=0;
      for(k=p[i]; k<=q[i]; k++)
        if(k!=1)
          s[i] = s[i] + (c[k-1][q[i]-1] - c[k-1][p[i]-2]);
        else
          s[i] = s[i] + c[k-1][q[i]-1];
      printf("%d\n",s[i]);
    }

  return 0;
} ./Main.c:5:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&N,&M,&Q);
   ^
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&L[i], &R[i]);
     ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&p[i], &q[i]);
     ^