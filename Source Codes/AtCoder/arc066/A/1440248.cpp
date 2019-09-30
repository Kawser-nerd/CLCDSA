#include <iostream>
using namespace std;
int n,cnt[1000005],i,x;
long long ans;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		cnt[x]++;
	}
	if (n&1)
	{
		for (i=2;i<=n;i+=2)
		{
			if (cnt[i]!=2)
			{
				cout<<0;
				return 0;
			}
		}
		if (cnt[0]!=1)
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		for (i=1;i<=n;i+=2)
		{
			if (cnt[i]!=2)
			{
				cout<<0;
				return 0;
			}
		}
	}
	ans=1;
	for (i=1;i<=n/2;i++) (ans*=2)%=((long long)1e9+7);
	cout<<ans;
	return 0;
}