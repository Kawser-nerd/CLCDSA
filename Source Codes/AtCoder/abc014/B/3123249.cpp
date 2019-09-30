#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,x,a,xx=1,s=0;cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if((x&xx)==xx)
		{
			s+=a;
		}
		xx*=2;
	}
	cout<<s<<endl;
	return 0;
}