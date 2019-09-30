#include<stdio.h>
#include<iostream>
using namespace std;
typedef __int64 LL;

int main()
{
	freopen("F:\\B-large.in","r",stdin);
	freopen("F:\\B-large.out","w",stdout);
	
	int T;
	int CN=0;
	
	scanf("%d",&T);
	while(T--)
	{
		LL c,l,p;
		scanf("%I64d%I64d%I64d",&l,&p,&c);
		int ans=0;
		while(l*c<p)
		{
			ans++;
			c=c*c;
		}
		printf("Case #%d: %d\n",++CN,ans);
	}
	//system("pause");
	return 0;
}
