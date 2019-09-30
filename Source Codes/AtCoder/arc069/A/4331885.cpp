#include <iostream>
using namespace std;
#define ll long long
ll mod=1e9+7;
int main()
{
	ll n,m;
	cin>>n>>m;
	if(n*2>=m)
	{
		cout<<m/2;
	}
	else
	{
		cout<<n+(m-n*2)/4;
	}
	return 0;
}