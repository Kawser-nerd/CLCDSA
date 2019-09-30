#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

//????????Dijkstra

struct edge
{
  int to, cost;
  edge(int t,int c){
		to=t;
		cost=c;
	}
	edge(){}
};

LL add(LL a,LL b){
  return (a+b)%mod;
}

typedef vector< vector < edge > > Graph;//?????

int min_path[100010]={};//s????????
template< typename T = LL >
vector< T > Dijkstra(Graph &g, int s)//??s????????????????vector???&
                                     //min_path???s????????????
{
  typedef pair< T, int > Pi;//cost,from
  vector< T > min_cost(g.size(), numeric_limits< T >::max());
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;//Pi:cost,from
  que.emplace(0, s);
  min_cost[s] = 0;
  min_path[s]=1;
  while(!que.empty()) {
    Pi p = que.top();
    que.pop();
    if(p.first > min_cost[p.second]) continue;
    for(auto &e : g[p.second]) {
      if(p.first + e.cost > min_cost[e.to]) continue;
			if(p.first + e.cost == min_cost[e.to]){
        min_path[e.to]=add(min_path[p.second],min_path[e.to]);//????????????????
				//min_path[e.to]=min_path[p.second]+min_path[e.to];//mod??
			}else {
				min_path[e.to]=min_path[p.second];//??????->??????
        min_cost[e.to] = p.first + e.cost;
        que.emplace(min_cost[e.to], e.to);
			}
    }
  }
  return (min_cost);
}

int main(){
	int n,q,k;
	cin>>n;
	Graph g=vector< vector < edge > >(n+1,vector < edge >(0));
	FOR(i,0,n-1){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].PB(edge(b,c));
		g[b].PB(edge(a,c));
	}
	cin>>q>>k;
	vector<int> x(q);
	vector<int> y(q);
	//cerr<<"test"<<endl;
	vector<LL> dist=Dijkstra(g,k);
	FOR(i,0,q){
		cin>>x[i]>>y[i];
		cout<<dist[x[i]]+dist[y[i]]<<endl;
	}

    return 0;
}