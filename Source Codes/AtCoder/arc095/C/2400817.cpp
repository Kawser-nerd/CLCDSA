#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,vis[15],vis2[15];
string st[15],st2[15],st3[15];
void check()
{
//	for (i=1;i<=n;i++) cerr<<st2[i]<<endl;
//	cerr<<endl;
	int i,j;
	for (i=1;i<=m;i++) st3[i]="";
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
		{
			st3[i].push_back(st2[j][i-1]);
		}
	}
	memset(vis2,0,sizeof(vis2));
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (vis2[j]) continue;
			if (i==j) continue;
			string t=st3[j];
			reverse(t.begin(),t.end());
			/*cerr<<st[i]<<endl;
			cerr<<t<<endl;*/
			if (st3[i]==t)
			{
				vis2[j]=1;
				break;
			}
		}
	}
	int cnt=0;
	for (i=1;i<=m;i++)
	{
		if (!vis2[i])
		{
			cnt++;
			string t=st3[i];
			reverse(t.begin(),t.end());
			if (st3[i]!=t) return;
		}
	}
	if (cnt>1) return;
	cout<<"YES";
	exit(0);
}
void dfs(int x,int y)
{
	if (x<=n) dfs(x+1,y);
	if (vis[x])
	{
		return;
	}
	if (x>n)
	{
		if (n%2==1&&y==(n+1)/2)
		{
			int cnt=0;
			for (i=1;i<=n;i++)
			{
				if (!vis[i])
				{
					cnt++;
					st2[y]=st[i];
				}
			}
			if (cnt<2) check();
		}
		if (y==(n+1)/2+1) check();
		return;
	}
	int i;
	for (i=x+1;i<=n;i++)
	{
		if (vis[i]) continue;
		st2[y]=st[x];
		st2[n-y+1]=st[i];
		vis[x]=1;
		vis[i]=1;
		dfs(x+1,y+1);
		vis[i]=0;
		vis[x]=0;
	}
	if (n%2==1&&y==(n+1)/2)
	{
		int cnt=0;
		for (i=1;i<=n;i++)
		{
			if (!vis[i])
			{
				cnt++;
				st2[y]=st[i];
			}
		}
		if (cnt<2) check();
	}
	vis[x]=0;
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>st[i];
	dfs(1,1);
	cout<<"NO";
	return 0;
}