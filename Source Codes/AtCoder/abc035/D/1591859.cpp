#include<iostream>
#include<vector>
#include<map>
#include<queue>
 
#define MAX_V 100005
#define INF 20000000000
using namespace std;
 
typedef pair<long long,long long>P;
struct edge{long long to,cost;};
long long dis[2][MAX_V];
vector<edge> G[2][MAX_V];
long long income[MAX_V];
long long v;
void dijkstra(long long t){
	priority_queue<P,vector<P>,greater<P> >que;
	for(long long i=1;i<=v;i++)dis[t][i]=INF;
	dis[t][1]=0;
	que.push(P(0,1));
	
	while(!que.empty()){
		P p =que.top();que.pop();
		long long v=p.second;
		if(dis[t][v]<p.first)continue;
		for(long long i=0;i<G[t][v].size();i++){
			edge e=G[t][v][i];
			if(dis[t][e.to]>dis[t][v]+e.cost){
				dis[t][e.to]=dis[t][v]+e.cost;
				que.push(P(dis[t][e.to],e.to));
			}
		}
	}
}
int main(){
	long long n,m,t;
	cin>>n>>m>>t;
	v=n;
	for(long long i=1;i<=n;i++)cin>>income[i];
	for(long long i=0;i<m;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		edge e;
		e.to=b;e.cost=c;
		G[0][a].push_back(e);
		e.to=a;
		G[1][b].push_back(e);
	}
	for(long long i=0;i<2;i++)dijkstra(i);
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long rt=t-(dis[0][i]+dis[1][i]);
		ans=max(ans,rt*income[i]);
	}
	cout<<ans<<endl;
}