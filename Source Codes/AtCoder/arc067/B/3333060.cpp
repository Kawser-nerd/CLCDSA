#include<iostream>
using namespace std;
long long pl=0;
long long x[100000000];
int main()
{
long long n,a,b;
cin>>n>>a>>b;
x[0]=0;
for(long long i=1;i<=n;i++)
{
cin>>x[i];
	if(i>1)
	{
	if(a*(x[i]-x[i-1])<=b)
	pl+=a*(x[i]-x[i-1]);
	else
	pl+=b;
	}
}
cout<<pl;
}