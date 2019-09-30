/*
    _____
  .'|||||'.
 /  >   <  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
    |||||
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
LL n,m;
int main()
{
    LL md=1e9+7;
scanf("%lld%lld",&n,&m);
if (abs(n-m)>=2) printf("0\n"); else
{
    LL ans=1;
    for (int i=1;i<=n;i++)
    ans=ans*(LL)i%md;
    if (m==n-1)
    {
        for (int i=1;i<=m;i++)
            ans=ans*(LL)i%md;
    } else
    if (m==n)
    {
        for (int i=2;i<=m;i++)
            ans=ans*(LL)i%md;
        ans=ans*2%md;
    } else
    if (m==n+1)
    {
        for (int i=1;i<=m;i++)
        ans=ans*(LL)i%md;
    }
    printf("%lld\n",ans);
}
    return(0);
}