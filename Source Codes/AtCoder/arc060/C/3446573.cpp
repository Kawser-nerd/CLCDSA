#include<iostream>
#include<cstdio>
using namespace std;
const int magic=307;
int n,x[111111],l,q,a,b,nxt[111111],bignxt[111111],pos,ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	scanf("%d",&l);
	pos=n;
	for (int i=n;i>=1;i--)
	{
		while(pos>=1 && x[pos]-x[i]>l) pos--;
		nxt[i]=pos;
	}
	for (int i=1;i<=n;i++)
	{
		pos=i;
		for (int j=1;j<=magic;j++)
		{
			pos=nxt[pos];
		}
		bignxt[i]=pos;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		if (a>b) swap(a,b);
		ans=0;
		while(bignxt[a]<b) 
		{
			ans+=magic;
			a=bignxt[a];
		}
		while(nxt[a]<b) 
		{
			ans++;
			a=nxt[a];
		}
		if (a!=b) ans++;
		printf("%d\n",ans);
	}
	return 0;
}