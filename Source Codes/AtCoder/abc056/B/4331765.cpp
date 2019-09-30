#include <iostream>
using namespace std;
#define ll long long
ll mod=1e9+7;
int main()
{
	ll w,a,b;
	cin>>w>>a>>b;
	if(b>(a+w))
	{
		cout<<b-a-w;
	}
	else if(b<=(a+w)&&b>=a)
	{
		cout<<0;
	}
	else if(b<a)
	{
		cout<<a-(b+w);
	}
	return 0;
}