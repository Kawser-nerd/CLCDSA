#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=510;
int a[maxn][maxn],dp[maxn][maxn];
int n,m,q;

int main()
{
    //freopen("1.txt","r",stdin);
    while (scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        int l,r;
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        while (m--)
        {
            scanf("%d%d",&l,&r);
            a[l][r]++;
        }
        for (int i=n;i>=1;i--)
            for (int j=i;j<=n;j++)
                dp[i][j]=a[i][j]+dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];

        while (q--)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",dp[l][r]);
        }
    }
    return 0;
}