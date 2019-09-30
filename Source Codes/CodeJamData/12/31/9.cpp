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

int a[10000][20], n, x, y;
bool flag, visit[10000];

void dfs(int i)
{
    if (visit[i])
        flag = 1;
    else
        for (int j=0;a[i][j]!=0;++j)
            dfs(a[i][j]);
    visit[i]=1;
}
     

int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    
    int TT;
    scanf("%d", &TT);
    for (int T=1;T<=TT;++T)
    {
        memset(a,0,sizeof(a)); 
        scanf("%d", &n);
        flag = 0;

        for (int i=1;i<=n;++i)
        {
            scanf("%d", &x);
            for (int j=0;j<x;++j)
                scanf("%d", &a[i][j]);
        }
        for (int i=1;i<=n;++i)
        {
            memset(visit, 0, sizeof(visit));
            dfs(i);
        }
        if (flag)
            printf("Case #%d: Yes\n", T);
        else
            printf("Case #%d: No\n", T);
    }
}
