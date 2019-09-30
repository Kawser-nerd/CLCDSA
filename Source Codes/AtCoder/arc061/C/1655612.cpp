#include<iostream>
#include<set>
#include<cstring>
#include<queue>
using namespace std;
struct edge{int to,color;};
vector<edge> w[100010];
int n,m,d[100010];
set<int> s[100010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		w[a].push_back({b,c});
		w[b].push_back({a,c});
	}
	memset(d,0x3f,sizeof d);
	d[1]=0;
	priority_queue<pair<int,int>> q;
	q.push({-d[1],1});
	while(!q.empty())
	{
		int now=q.top().second,cost=-q.top().first;q.pop();
		if(d[now]<cost) continue;
		for(edge j:w[now])
		{
			int dis=d[now];
			if(!s[now].count(j.color))dis++;
			if(dis<d[j.to])
			{
				d[j.to]=dis;
				s[j.to].clear();
				s[j.to].insert(j.color);
				q.push({-d[j.to],j.to});
			}
			else if(dis==d[j.to])s[j.to].insert(j.color);
		}
	}
	if(d[n]>4e5)cout<<-1<<endl;
	else cout<<d[n]<<endl;
	return 0;
}