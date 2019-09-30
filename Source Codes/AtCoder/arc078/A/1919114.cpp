#include<iostream>
#include<cmath>
using namespace std;
	const long long size=2e5+1;
	long long a[size],x[size];
	long long n,s;
int main()
{

	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	    x[i]=x[i-1]+a[i];
	    s+=a[i];
	}
	
	
	long long min=2e10+5,result;
	for(int i=1;i<n;i++)
	{
	result=abs(2*x[i]-s);
	if(min>result)
	min=result;
	}
	

	cout<<min;
	return 0;
	
	
	
	
 }