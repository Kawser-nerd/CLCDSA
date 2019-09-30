#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int a[10000], b[10000], n, m;
long long x[10000], y[10000], sx[200][200], sy[200][200], dp[200][200];



int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    
    int TT;
    scanf("%d", &TT);
    for (int T=1;T<=TT;++T)
    {
        scanf("%d%d", &n,&m); 
        for (int i=1;i<=n;++i)
            scanf("%I64d%d", x+i, a+i);
        for (int i=1;i<=m;++i)
            scanf("%I64d%d", y+i, b+i);
        memset(sx,0,sizeof(sx));
        memset(sy,0,sizeof(sy));
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;++i)
            for (int k=1;k<=100;++k)
                sx[i][k]=sx[i-1][k] + (a[i] == k)*x[i];
        for (int i=1;i<=m;++i)
            for (int k=1;k<=100;++k)
                sy[i][k]=sy[i-1][k] + (b[i] == k)*y[i];
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                if (a[i]==b[j])
                {
                    int k=a[i];
                    for (int ii=1;ii<=i;++ii) if (k==a[ii]) 
                        for (int jj=1;jj<=j;++jj) if (k==b[jj])
                            dp[i][j]=max(dp[i][j], dp[ii-1][jj-1] + min(sx[i][k]-sx[ii-1][k], sy[j][k]-sy[jj-1][k]));
                }
            }
        printf("Case #%d: %I64d\n", T, dp[n][m]);
    }
}
