#include<iostream>
using namespace std;
const int maxn = 1e6+10;

int m,n;
int main()
{
	long long x,y,j,ans=0;
	cin>>x>>y;
	j=x;
	while(j<=y)
	{
		j*=2;
		ans++;
	}
	cout<<ans;
}