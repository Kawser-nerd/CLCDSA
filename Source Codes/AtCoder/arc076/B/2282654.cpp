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
int n;
int par[100005];
int px[100005],py[100005];
pair<int,int> ex[100005],ey[100005];
long long ans;
int find(int x)
{
	if(par[x]==x)
		return x;
	else
		return par[x]=find(par[x]);
}
bool unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return false;
	par[x]=y;
	return true;
}
int dist(int x,int y)
{
	return min(abs(px[x]-px[y]),abs(py[x]-py[y]));
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>px[i]>>py[i];
		par[i]=i;
		ex[i]=make_pair(px[i],i);
		ey[i]=make_pair(py[i],i);
	}
	sort(ex,ex+n);
	sort(ey,ey+n);
	set<pair<int,pair<int,int> > > s; 
	for(int i=0;i<n-1;i++)
	{
		s.insert(make_pair(dist(ex[i].second,ex[i+1].second),make_pair(ex[i].second,ex[i+1].second)));
		s.insert(make_pair(dist(ey[i].second,ey[i+1].second),make_pair(ey[i].second,ey[i+1].second)));
	}
	while(!s.empty())
	{
		pair<int,pair<int,int> > x=*s.begin();
		s.erase(x);
		int a=x.second.first;
		int b=x.second.second;
		ans+=(long long)unite(a,b)*(long long)dist(a,b);
	}
	cout<<ans;
	return 0;
}