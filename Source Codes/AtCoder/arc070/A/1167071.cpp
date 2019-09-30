#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
#define maxn 10010
#define llg long long 
#define yyj(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout);
llg n,m,mid,ans,x;
int main()
{
	scanf("%lld",&x);
	llg l=1,r=1e9;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if ((llg)mid*(mid+1)/2>=x) {r=mid-1,ans=mid;} else l=mid+1;
	}
	printf("%lld",ans);
	return 0;
}