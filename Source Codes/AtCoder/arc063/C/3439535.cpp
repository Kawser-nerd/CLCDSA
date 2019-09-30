#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cassert>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<iomanip>
#include<utility>
#include<functional>
using namespace std;
const int INF=1000000009;
int n,k;
int a[100005];
int l[100005],r[100005];
int par[100005];
int root;
vector<int> edge[100005];
void getara(int x,int prev)
{
	if(a[x]!=-1)
		l[x]=r[x]=a[x];
	for(int i=0;i<edge[x].size();i++)
	{
		int y=edge[x][i];
		if(y!=prev)
		{
			getara(y,x);
			if(l[y]==-INF)
				continue;
			if(l[x]==-INF)
			{
				l[x]=l[y]-1;
				r[x]=r[y]+1;
			}
			else
			{
				if(abs(l[x]%2)==abs(l[y]%2))
				{
					cout<<"No";
					exit(0);
				}
				l[x]=max(l[x],l[y]-1);
				r[x]=min(r[x],r[y]+1);
			}
		}
	}
	if(l[x]>r[x])
	{
		cout<<"No";
		exit(0);
	}
}
void getans(int x,int prev)
{
	for(int i=0;i<edge[x].size();i++)
	{
		int y=edge[x][i];
		if(y!=prev)
		{
			if(a[y]==-1)
			{
				if(l[y]<=a[x]+1&&r[y]>=a[x]+1)
					a[y]=a[x]+1;
				else
					a[y]=a[x]-1;
			}
			getans(y,x);
		}
	}	
}
int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	memset(a,-1,sizeof(a));
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int x,v;
		cin>>x>>v;
		x--;
		root=x;
		a[x]=v;
	}
	for(int i=0;i<n;i++)
	{
		l[i]=-INF;
		r[i]=INF;
	}
	getara(root,-1);
	getans(root,-1);
	cout<<"Yes"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
	return 0;
}