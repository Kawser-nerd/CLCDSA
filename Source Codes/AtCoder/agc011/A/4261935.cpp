#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int t[100010],n,c,k;
bool jd(int x)
{
	int cnt=1; bool flag=true;
	for(int i=2;i<=n;i++)
	{
		if(t[i]-t[i-cnt]>k) {x--;cnt=0;}
		if(t[i]-t[i-cnt]<=k)
		{
			cnt++;
		}
		if(cnt==c) {x--;cnt=0;}
		if(x<0) {flag=false;break;}
	}
	if(flag==false) return false;
	else return true;
}
int main()
{
	scanf("%d%d%d",&n,&c,&k);
	for(int i=1;i<=n;i++) cin>>t[i];
	sort(t+1,t+1+n);
	int head=1,tail=n,mid;
	while(head<tail)
	{
		mid=(head+tail)/2;
		if(jd(mid-1)==false) head=mid+1;
		else tail=mid;
	}
	printf("%d",tail);
	return 0;
}