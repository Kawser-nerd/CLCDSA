#include<iostream>
#define int long long
using namespace std;
int n;
string a,b;
signed main()
{
	cin>>n>>a>>b;
	int ans=1,mod=1000000007;
	for(int i=0;i<n;i++)
		if(a[i]==b[i])
			if(!i)ans=3;
			else if(a[i-1]==b[i-1])ans=(ans*2)%mod;
			else{}
		else
		{
			if(!i)ans=6;
			else if(a[i-1]==b[i-1])ans=(ans*2)%mod;
			else ans=(ans*3)%mod;
			i++;
		}
	cout<<ans<<endl;
}