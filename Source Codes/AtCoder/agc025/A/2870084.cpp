#include<iostream>
using namespace std;
const int maxn = 1e6+10;
int m,n;
int main()
{
	cin>>n;
	int ans=0;
	if(n%10!=0)
	{
		while(n)
		{
			ans+=n%10;
			n/=10;
		}
	}
	else 
	{
		n/=2;
		while(n)
		{
			ans+=n%10;
			n/=10;
		}
		ans*=2;
	}
	cout<<ans;
}