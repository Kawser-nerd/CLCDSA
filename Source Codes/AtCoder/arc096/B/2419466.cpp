#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
long long a[100010],b[100010],x[100010],v[100010];

int main()
{
//	cout<<a[0]<<" "<<b[0];
	long long n,c;
	cin>>n>>c;
	cin>>x[1]>>v[1];
	a[1]=v[1]-x[1];
	for(int i=2;i<=n;i++){
		cin>>x[i]>>v[i];
		a[i]=a[i-1]-x[i]+v[i]+x[i-1];
	}
	b[1]=v[n]-(c-x[n]);
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]-(c-x[n-i+1])+v[n-i+1]+(c-x[n-i+2]);
	}
	long long ans=0;
	for(int i=2;i<=n;i++){
		a[i]=max(a[i-1],a[i]);
		b[i]=max(b[i-1],b[i]);
		ans=max(ans,max(a[i],b[i]));
	}
        ans=max(ans,max( a[n],b[n]) ) ;
	long long ans1=0,ans2=0;
	for(int i=1;i<=n;i++){
		
		ans1=max(ans1, a[i]-x[i]+b[n-i] );
		ans2=max(ans2, b[i]-(c-x[n-i+1])+a[n-i] );
	}
	cout<<max( ans, max(ans1,ans2) )<<endl;
}