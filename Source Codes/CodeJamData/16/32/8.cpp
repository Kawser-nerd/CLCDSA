#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T;
int n;
long long m;
long long f[100];
int g[100][100];

int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);

    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {

        scanf("%d%I64d",&n,&m);
        printf("Case #%d: ",t);

        f[n]=1;f[n-1]=1;
        for(int i=n-2;i;i--)
            f[i]=(long long)f[i+1]*2;
        if(m>f[1])
            printf("IMPOSSIBLE\n");
        else
        {
            printf("POSSIBLE\n");
            memset(g,0,sizeof(g));
            for(int i=2;i<=n;i++)
                if(m>=f[i])
                {
                    m-=(long long)f[i];
                    g[1][i]=1;
                }
            for(int i=2;i<n;i++)
                for(int j=i+1;j<=n;j++)
                    g[i][j]=1;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                    printf("%d",g[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
