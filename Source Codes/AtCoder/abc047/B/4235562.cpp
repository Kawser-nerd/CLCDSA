#include <iostream>
using namespace std;
#define ll long long
#include <string>
#include <algorithm>
int main()
{
	ll w,h,x,y,n,a;
	ll t1,t2;

	cin>>w>>h>>n;
	ll x1=0,y1=0,x2=w,y2=h;
	t1=w;t2=h;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>a;
		if(a==1)
		{
			if(x>x1)
			x1=x;
		}
		if(a==2)
		{
			if(x2>x)
			x2=x;
		}
		if(a==3)
		{
			if(y>y1)
			y1=y;
		}
		if(a==4)
		{
			if(y2>y)
			y2=y;
		}
		//	cout<<w<<"  "<<h<<endl;
	}
	ll ww=x2-x1;ll hh=y2-y1;
	if(ww<=0||hh<=0)
	{
		cout<<0;
	}
	else
	{
		cout<<ww*hh<<endl;
	}
	return 0;
}