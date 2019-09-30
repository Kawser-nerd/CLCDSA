#include <iostream>
using namespace std;
#define ll long long
int main()
{
	ll a,b,c;
	cin>>a>>b>>c;
	
	if(a+b==c||b+c==a||a+c==b)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}