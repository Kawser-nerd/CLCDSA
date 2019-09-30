#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,a[111111],b[111111],c[111111],d[111111],ans=0;
signed main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	for(int i=0;i<n;i++)cin>>c[i];
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	for(int i=n-1;i>=0;i--)d[i]=d[i+1]+n-(upper_bound(c,c+n,b[i])-c);
	for(int i=0;i<n;i++)ans+=d[upper_bound(b,b+n,a[i])-b];
	cout<<ans<<endl;
	return 0;
}