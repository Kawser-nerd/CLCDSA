#include <stdio.h>

int main()
{
    int N, M, A;
    int nCases;
    scanf("%i", &nCases);
    int Area;
    for(int c = 1; c <= nCases; c++)
    {
        scanf("%i %i %i", &N, &M, &A);
        //printf("%i %i %i", N, M, A);
        if(A > (M*N))
            printf("Case #%i: IMPOSSIBLE\n", c);
        else
        {
            int ok = 0;
            for(int x1 = 0; x1 <= N; x1++)
            {
                for(int y1 = 0; y1 <= M; y1++)
                {
                    for(int x2 = 0; x2 <= N; x2++)
                    {
                        for(int y2 = 0; y2 <= M; y2++)
                        {
                            for(int x3 = 0; x3 <= N; x3++)
                            {
                                for(int y3 = 0; y3 <= M; y3++)
                                {
                                    Area = x1*y2 + y1*x3 + x2*y3 - y2*x3 - x1*y3 - y1*x2;
                                    if(Area == A)
                                    {
                                        printf("Case #%i: %i %i %i %i %i %i\n", c, x1, y1, x2, y2, x3, y3);
                                        ok = 1;
                                        break;
                                    }
                                }
                                if(ok) break;
                            }
                            if(ok) break;
                        }
                        if(ok) break;
                    }
                    if(ok) break;
                }
                if(ok) break;
            }
            if(!ok) printf("Case #%i: IMPOSSIBLE\n", c);
        }
    }
}
