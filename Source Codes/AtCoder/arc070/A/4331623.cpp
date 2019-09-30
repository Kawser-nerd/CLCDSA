#include <iostream>
using namespace std;
#define ll long long
int main()
{
	ll x;
	cin>>x;
	int i=1;
	ll sum=0;
	while(sum<x)
	{
		sum=sum+i;
		i++;
	}
	cout<<i-1;
	return 0;
}