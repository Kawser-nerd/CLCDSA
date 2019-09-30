#include <iostream>
using namespace std;
#define ll long long
ll mod=1e9+7;
int main()
{
	ll n,sum=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		sum=i*sum;
		sum=sum%mod;
	}
	cout<<sum;
	return 0;
}