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
int n,ans,x[200],y[200];
int main()
{
scanf("%d",&n);
for (int i=1;i<=n;i++)
{
    scanf("%d",&x[i]);
    ans+=x[i];
}
if (ans%10!=0) printf("%d\n",ans); else
{
    sort(x+1,x+1+n);
    int o=0;
    for (int i=1;i<=n;i++)
        if (x[i]%10!=0)
    {
        o++;
        y[o]=x[i];
    }
    if (o==0) printf("0\n"); else
    {
        printf("%d\n",ans-y[1]);
    }

}
    return(0);
}