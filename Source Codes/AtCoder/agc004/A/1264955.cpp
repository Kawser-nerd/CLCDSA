#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

#define rep(i,x,y) for (int i=x;i<=y;i++)
#define dep(i,y,x) for (int i=y;i>=x;i--)
#define sz(x) (int)(x.size())

using namespace std;

typedef long long LL; 
typedef unsigned long long uLL;

const LL INF=(1e18)+7;

LL a,b,c,ans;

int main()
{
 scanf("%lld%lld%lld",&a,&b,&c);

 ans=INF;
 if (a&1) ans=min(ans,b*c); else ans=0;
 if (b&1) ans=min(ans,a*c); else ans=0;
 if (c&1) ans=min(ans,a*b); else ans=0;

 printf("%lld\n",ans);

 // system("pause");
 return 0;
}