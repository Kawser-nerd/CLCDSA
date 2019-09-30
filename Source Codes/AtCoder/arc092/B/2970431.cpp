#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200100
using namespace std;

int n,a[N],b[N],M,l,r,mid,ans,an;

inline int find(int u)
{
	int l=1,r=n+1,mid;
	for(;l<r;)
	{
		mid=((l+r)>>1);
		if(b[mid]>=u) r=mid;
		else l=mid+1;
	}
	return l;
}

int main()
{
	int i,j,p,q;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	for(M=(1 << 29),i=(1 << 28);M>=2;M>>=1,i>>=1)
	{
		an=0;
		for(j=1;j<=n;j++)
		{
			a[j]%=M;
			b[j]%=M;
		}
		sort(b+1,b+n+1);
		for(j=1;j<=n;j++)
		{
			an^=(((find(2*i-a[j])-find(i-a[j]))+(n-find(3*i-a[j])+1))&1);
		}
		an&=1;
		ans+=an*(M>>1);
	}
	cout<<ans;
}