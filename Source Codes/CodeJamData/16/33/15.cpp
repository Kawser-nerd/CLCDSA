#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<complex>
#include<ctime>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vi::iterator vit;
typedef set<ll> si;
typedef si::iterator sit;
typedef vector<pii> vpi;

#define sq(x) ((x)*(x))
#define all(x) (x).begin(),(x).end()
#define cl(x) memset(x,0,sizeof(x))
#define LL "%I64d"
//#define LL "%lld"
#define RLL(x) scanf(LL,&(x))

void test(int T)
{
	int j, p, s, k;
	cin>>j>>p>>s>>k;
	int s1 = min(s, k);
	printf("Case #%d: %d\n", T, j * p * s1);
	int cur = 0;
	for(int i0 = 0; i0 < j; ++i0)
	{
		for(int i1 = 0; i1 < p; ++i1)
			for(int i2 = 0; i2 < s1; ++i2)
			{
				printf("%d %d %d\n", i0+1, i1+1, cur+1);
				cur = (cur+1)%s;
			}
		cur = (i0+1)%s;
	}
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i)
		test(i+1);
    return 0;
}