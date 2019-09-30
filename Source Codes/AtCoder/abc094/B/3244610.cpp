#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
	int a[110],n,m,x;
	cin>>n>>m>>a[0];
	x=a[0];
	for(int i=1;i<=m;i++)cin>>a[i];
	sort(a,a+m+1);
	for(int i=1;i<=m+1;i++)
	{
		if(a[i-1]==x)
		{
			cout<<min(i-1,m+1-i)<<endl;
			return 0;
		}
	}
	return 0;
}