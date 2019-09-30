#include<cstdio>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<numeric>
#include<cctype>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
using namespace std;
#define N 100000+5
#define rep(i,n) for(int i=0;i<n;i++)
#define sd(n) scanf("%d",&n)
#define sll(n) scanf("%I64d",&n)
#define pd(n) scanf("%d\n",n)
#define pll(n) scanf("%I64d\n",n)
#define MAX 26
typedef long long ll;
const ll mod=1e9+7;
ll n,m;
ll a[N];
ll b[N];
vector<ll>p[N];
int main()
{
	 //string s;
	 //cin>>s;
	 //ll ans=0;
	 //ll sum=0;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		p[a[i]].push_back(b[i]);
	}
	for(int i=1;i<=n;i++)
	  sort(p[i].begin(),p[i].end());
	for(int i=0;i<m;i++)
	{

		int pos=lower_bound(p[a[i]].begin(),p[a[i]].end(),b[i])-p[a[i]].begin()+1;
		printf("%06lld%06lld\n",a[i],pos);
	}
	//for(int i=1;i<=n;i++)
	//	printf("%I64d",a[i]);
		
	//printf("%I64d\n",ans);
    return 0;
} ./Main.cpp:39:13: warning: format specifies type 'int *' but the argument has type 'll *' (aka 'long long *') [-Wformat]
        scanf("%d",&n);
               ~~  ^~
               %lld
./Main.cpp:40:13: warning: format specifies type 'int *' but the argument has type 'll *' (aka 'long long *') [-Wformat]
        scanf("%d",&m);
               ~~  ^~
               %lld
./Main.cpp:52:32: warning: format specifies type 'long long' but the argument has type 'int' [-Wformat]
                printf("%06lld%06lld\n",a[i],pos);
                              ~~~~~~         ^~~
                              %06d
3 warnings generated.