#include <iostream>
using namespace std;
#define ll long long
#include <string>
#include <algorithm>
int main()
{
	ll a,b,c,d,count=0;
	
//	while(1)
//	{
	cin>>a>>b>>c;
	ll t1,t2,t;
	t1=a/c;
	t2=b/c;
	if(a%c==0)
	{
		t=t2-t1+1;
	}
	else
	{
		t=t2-t1;
	}
	cout<<t;
	return 0;
}