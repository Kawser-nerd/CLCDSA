#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=24*60;
int n,m,f[N+10][N+10][5][5],a[N+10];

int main()
{
    #ifdef LOCAL
    freopen("B-large.in","r",stdin);
    freopen("b-large.out","w",stdout);
    #endif //LOCAL
    int T,w=0;
    for (scanf("%d",&T); T--; )
    {
        scanf("%d%d",&n,&m);
        for (int i=0; i<N; i++) a[i]=-1;
        for (int i=1; i<=n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            for (int j=x; j<y; j++) a[j%N]=1;
        }
        for (int i=1; i<=m; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            for (int j=x; j<y; j++) a[j%N]=0;
        }

        for (int i=0; i<N; i++)
        for (int j=0; j<=N/2; j++)
        for (int k=0; k<4; k++) f[i][j][k/2][k%2]=2*N;
        f[0][0][0][0]=0,f[0][1][1][1]=0;

        for (int i=1; i<N; i++)
        for (int j=0; j<=N/2; j++)
        for (int k=0; k<2; k++)
        {
            for (int last=0; last<2; last++)
            {
                if (a[i]==-1 || 0==a[i])
                    f[i][j][0][k]=min(f[i][j][0][k],f[i-1][j][last][k]+(last!=0));
                if (j!=0)
                    if (a[i]==-1 || 1==a[i])
                        f[i][j][1][k]=min(f[i][j][1][k],f[i-1][j-1][last][k]+(last!=1));
            }
        }
        int ans=2*N;
        for (int x=0; x<2; x++)
        for (int y=0; y<2; y++) ans=min(ans,f[N-1][N/2][x][y]+(x!=y));

        printf("Case #%d: %d\n",++w,ans);
    }
    return 0;
}
