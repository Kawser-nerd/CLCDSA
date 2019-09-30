#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
int n;
long long m;

ll a[200000+10];
int v[200000+10];
int qz=0;

namespace solver
{
 // struct node
 // {
 //   int x,y;
 //	ll v;
  //};
  //queue<node> q;
  void solve()
  {
    //freopen("in","r",stdin);;
    //freopen("out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	ll all=0;
    for(int i=1; i<=n-1; ++i)
	  if(a[i] + a[i+1] >= m)
	  {
	    puts("Possible");
		for(int j=1; j<i; ++j) printf("%d\n",j);
		for(int j=n-1; j>=i; --j) printf("%d\n",j);
	    return;
	  }
    puts("Impossible");
  }
}
int main()
{
  solver::solve();
}