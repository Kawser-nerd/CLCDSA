#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n,h,mx,ans;

int main()
{
	cin>>n>>h;
	
	vector<ll> v(n);
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a>>v[i];
		mx=max(mx,a);
	}
	
	sort(v.begin(),v.end());
	while(h>0&&!v.empty())
	{
		ll t=v.back();
		if(t<=mx) break;
		ans++;
		h-=t;
		v.pop_back();
	}
	
	if(h>0) ans+=(h+mx-1)/mx;
	
	cout<<ans;
	
	return 0;
}