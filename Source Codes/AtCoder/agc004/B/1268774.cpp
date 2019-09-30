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

const int maxn=2000+7;

int n,k;
LL a[maxn],cur[maxn],K,x,ans;

int main()
{
 scanf("%d%lld",&n,&K);
 rep(i,1,n) scanf("%lld",&a[i]);

 ans=0;
 rep(i,1,n) ans+=a[i],cur[i]=a[i];

 rep(i,1,n)
 {
  rep(j,1,n)
  {
   k=j-i;
   if (k<=0) k+=n;
   cur[j]=min(cur[j],a[k]);
  }

  x=i*K;
  rep(j,1,n) x+=cur[j];

  // printf("%lld\n",x);
  ans=min(ans,x);
 }
 
 printf("%lld\n",ans);

 // system("pause");
 return 0;
}