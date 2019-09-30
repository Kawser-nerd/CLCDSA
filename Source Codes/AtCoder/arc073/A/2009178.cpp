#include<iostream>
using namespace std;
int n,t,a[200005],l,r,j;
long long s;
int main()
{
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	for(int i=1;i<=n;i++)
	{
	  if(i==n)s+=t;
	  else if(a[i+1]-a[i]<=t)s=s+a[i+1]-a[i];
	  else if(a[i+1]-a[i]>t)s+=t;
	}
	cout<<s;
	return 0;
}