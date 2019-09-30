#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
#define int long long
	int n,k,a[10000];
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++)scanf("%lld",a+i);
	sort(a,a+n);
	int sum=0,ans=0;
	for(int i=n-1;i>=0;i--)
		if(sum+a[i]<k)sum+=a[i],ans++;
		else ans=0;
	printf("%lld\n",ans);
	return 0;
}