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
int n,k;
int a[100005];
vector<int> edge[100005];

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
	priority_queue<pair<int,int> > q;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int x,v;
		cin>>x>>v;
		x--;
		a[x]=v;
		q.push(make_pair(-v,x));
	}
	while(!q.empty())
	{
		int x,v;
		x=q.top().second;
		q.pop();
		for(int i=0;i<edge[x].size();i++)
		{
			int y=edge[x][i];
			if(a[y]==-1)
			{
				a[y]=a[x]+1;
				q.push(make_pair(-a[y],y));
			}
		}
	}
	for(int x=0;x<n;x++)
		for(int i=0;i<edge[x].size();i++)
		{
			int y=edge[x][i];
			if(a[x]-a[y]!=1&&a[x]-a[y]!=-1)
			{
				cout<<"No";
				return 0;
			}
		}
	cout<<"Yes"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
	return 0;
}