#include <cstdio>
#include <algorithm>
using namespace std;

int N;
double sz[2][1000];

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%lf", sz[0]+i);
        for(int i=0; i<N; i++)
            scanf("%lf", sz[1]+i);
        sort(sz[0], sz[0]+N);
        sort(sz[1], sz[1]+N);
        int DW=0, WW=0;
        {
            double *ab=sz[0], *ae=sz[0]+N;
            double *bb=sz[1], *be=sz[1]+N;
            while(ab<ae)
            {
                if(*ab < *bb)
                {
                    ab++;
                }
                else
                {
                    DW++;
                    ab++;
                    bb++;
                }
            }
        }
        {
            WW=N;
            double *ab=sz[0], *ae=sz[0]+N;
            double *bb=sz[1], *be=sz[1]+N;
            while(ab<ae)
            {
                if(be[-1] > ae[-1])
                {
                    be--;
                    ae--;
                    WW--;
                }
                else
                {
                    ae--;
                }
            }
        }
        printf("Case #%d: %d %d\n", t, DW, WW);
    }
    return 0;
}
