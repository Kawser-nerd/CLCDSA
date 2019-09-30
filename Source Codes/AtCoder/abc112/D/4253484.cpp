#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=m/n;i>=1;i--)
	{
		if(m%i==0)
		{
			int t=m/i;
			if(t>=n)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
}