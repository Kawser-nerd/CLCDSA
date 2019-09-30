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
int n,m;
int ans;
int par[100005];
vector<int> edge[100005];
vector<pair<int,int> > el;
pair<int,int> e[200005];
pair<pair<int,int>,int> a[100005],b[100005];
int find(int x)
{
	if(par[x]!=x)
		return par[x]=find(par[x]);
	else
		return par[x];
}
bool unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return false;
	else
	{
		par[x]=y;
		return true;
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first.first>>a[i].first.second;
		b[i].first.first=a[i].first.second;
		b[i].first.second=a[i].first.first;
		a[i].second=b[i].second=i;
	}
	sort(a,a+n);
	sort(b,b+n);
	for(int i=1;i<n;i++)
	{
		edge[a[i].second].push_back(a[i-1].second);
		e[m]=make_pair(a[i].second,a[i-1].second);
		el.push_back(make_pair(a[i].first.first-a[i-1].first.first,m++));
	}
	for(int i=1;i<n;i++)
	{
		edge[b[i].second].push_back(b[i-1].second);
		e[m]=make_pair(b[i].second,b[i-1].second);
		el.push_back(make_pair(b[i].first.first-b[i-1].first.first,m++));
	}
	for(int i=0;i<n;i++)
		par[i]=i;
	sort(el.begin(),el.end());
	for(int i=0;i<m;i++)
	{
		int xx=e[el[i].second].first;
		int yy=e[el[i].second].second;
		if(unite(xx,yy))
			ans+=el[i].first;
	}
	cout<<ans;
	return 0;
}