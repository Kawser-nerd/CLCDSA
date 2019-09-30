#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;
int main()
{
	int n,m,d,ans;cin>>n>>m;
	pair<int,int> a[55],c[55];
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	for(int i=1;i<=m;i++)cin>>c[i].first>>c[i].second;
	for(int i=1;i<=n;i++)
	{
		ans=0;
		d=1<<30;
		for(int j=m;j>=1;j--)
		{
			if(d>=abs(a[i].first-c[j].first)+abs(a[i].second-c[j].second))
			{
				ans=j;
				d=abs(a[i].first-c[j].first)+abs(a[i].second-c[j].second);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}