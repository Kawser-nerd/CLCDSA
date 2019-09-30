#include <stdio.h>

inline int abs(int x) { return x>0?x:-x;}
inline int min(int x, int y) { return x<y?x:y;}

int main()
{
  int T;
  int D,I,M,N;
  int A[200];
  int C[200][256];

  int t,m,n,x,y,z,k, tmp;

  scanf("%d\n", &T);
  for (t=1; t<=T; t++)
  {
    scanf("%d %d %d %d\n", &D, &I, &M, &N);
    for (n=0; n<N; n++) scanf("%d", A+n);
    scanf("\n");

    for (x=0; x<256; x++)
    {
      tmp = abs(A[0]-x);
      if (M) for (y=0; y<256; y++)
      {
        tmp = min(tmp, abs(A[0]-y) + I*((abs(x-y)+M-1)/M));
      }
      C[0][x] = tmp;
    }

    for (k=1; k<N; k++)
    {
      for (x=0; x<256; x++)
      {
        tmp = C[k-1][x] + D;
        for (y=0; y<256; y++)
          if (M) for (z=0; z<256; z++)
          {
            if (abs(y-z) > M) continue;
            tmp = min(tmp, C[k-1][y] + abs(A[k]-z) + I*((abs(x-z)+M-1)/M));
          }
          else
          {
            if (abs(y-x) > M) continue;
            tmp = min(tmp, C[k-1][y] + abs(A[k]-x));
          }
        C[k][x] = tmp;
      }
    }

    tmp = C[N-1][0];
    for (x=0; x<256; x++)
      tmp = min(tmp, C[N-1][x]);

    printf("Case #%d: %d\n", t, tmp);
  }

  return 0;
}
