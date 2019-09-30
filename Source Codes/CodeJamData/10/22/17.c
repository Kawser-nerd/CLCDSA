#include <stdio.h>

int main(void)
{
   int C, c;

   scanf("%d", &C);
   for(c = 1; c <= C; ++c)
   {
      int X[64], V[64], M[64];
      int N, K, B, T, i, s = 0;

      scanf("%d%d%d%d", &N, &K, &B, &T);

      for(i = 0; i < N; ++i)
      {
         scanf("%d", X + i);
      }

      for(i = 0; i < N; ++i)
      {
         scanf("%d", V + i);
      }

      for(i = 0; i < N; ++i)
      {
         M[N-i-1] = (T*V[i] >= B - X[i]);
      }

      if(K == 0)
         printf("Case #%d: 0\n", c);
      else
         for(i = 0; i < N; ++i)
         {
            int j;

            if(M[i])
            {
               if(i + 1 >= K)
               {
                  printf("Case #%d: %d\n", c, s);
                  break;
               }
               continue;
            }

            for(j = i + 1; j < N; ++j)
            {
               if(M[j])
                  break;
            }

            if(j < N)
            {
               M[i] = 1;
               M[j] = 0;
               s += j - i;
               if(i + 1 >= K)
               {
                  printf("Case #%d: %d\n", c, s);
                  break;
               }
            }
            else
            {
               printf("Case #%d: IMPOSSIBLE\n", c);
               break;
            }
         }
   }

   return 0;
}
