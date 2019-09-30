#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<tuple>
#include<map>
using namespace std;
vector<pair<int,int>>x[20000];
long long a[120000],b[120000],c[120000],n,m,e,dist[20000];
int d[10000][10105];
inline void dijkstra1(){
	for(int i=0;i<n;i++)dist[i]=999999999;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
	Q.push(make_pair(0,0));dist[0]=0;
	while(!Q.empty()){
		int a1=Q.top().first,a2=Q.top().second;Q.pop();
		for(int i=0;i<(int)x[a2].size();i++){
			int to=x[a2][i].first,cost=x[a2][i].second;
			if(dist[to]>a1+cost){
				dist[to]=a1+cost;
				Q.push(make_pair(dist[to],to));
			}
		}
	}
}
inline void dijkstra2(){
	d[0][0]=0;
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>Q;
	Q.push(make_tuple(0,0,0));
	while(!Q.empty()){
		int a1=get<0>(Q.top()),a2=get<1>(Q.top()),a3=get<2>(Q.top());Q.pop();
		for(int i=0;i<(int)x[a2].size();i++){
			int to1=x[a2][i].first,to2=a3+x[a2][i].second,cost=1;
			if(x[a2][i].second==1)cost=to2;
			
			if(to2>dist[to1]+e-1)continue;
			if(d[to1][to2]>a1+cost){
				d[to1][to2]=a1+cost;
				Q.push(make_tuple(d[to1][to2],to1,to2));
			}
		}
	}
}
int main(){
	cin>>n>>m;e=sqrt(2*n)+2;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&c[i],&a[i],&b[i]);
		x[a[i]].push_back(make_pair(b[i],c[i]));
		x[b[i]].push_back(make_pair(a[i],c[i]));
	}
	dijkstra1();
	for(int i=0;i<n;i++){
		for(int j=dist[i];j<dist[i]+e;j++){
			d[i][j]=999999999;
		}
	}
	dijkstra2();
	for(int h=0;h<n;h++){
		int minx=999999999;
		for(int i=dist[h];i<dist[h]+e;i++)minx=min(minx,d[h][i]);
		printf("%d\n",minx);
	}
	return 0;
} ./Main.cpp:49:18: warning: format specifies type 'int *' but the argument has type 'long long *' [-Wformat]
                scanf("%d%d%d",&c[i],&a[i],&b[i]);
                       ~~      ^~~~~
                       %lld
./Main.cpp:49:24: warning: format specifies type 'int *' but the argument has type 'long long *' [-Wformat]
                scanf("%d%d%d",&c[i],&a[i],&b[i]);
                         ~~          ^~~~~
                         %lld
./Main.cpp:49:30: warning: format specifies type 'int *' but the argument has type 'long long *' [-Wformat]
                scanf("%d%d%d",&c[i],&a[i],&b[i]);
                           ~~              ^~~~~
                           %lld
3 warnings generated.