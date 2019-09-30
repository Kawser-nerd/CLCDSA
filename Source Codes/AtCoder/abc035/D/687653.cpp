#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
typedef struct {int to, cost;} edge;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define MAX_N 100000
#define MAX_M 100000
#define INF 1000000000

long long int N, M, T;
long long int A[MAX_N];
//vector<int> path[MAX_N];
vector<edge> path[MAX_M];
vector<edge> path_r[MAX_M];
int dist_go[MAX_N];
int dist_back[MAX_N];

void dijkstra(vector<edge> _path[], int* dist){
  fill(dist, dist+N, INF);
  dist[0] = 0;
  priority_queue<pint, vector<pint>, greater<pint> > que;
  que.push(pint(0, 0));
  while(!que.empty()){
    pint p = que.top(); que.pop();
    int v = p.second;
    if(dist[v] < p.first) continue;
    rep(i, _path[v].size()){
      edge e = _path[v][i];
      if(dist[e.to] > dist[v]+e.cost){
	dist[e.to] = dist[v]+e.cost;
	que.push(pint(dist[e.to], e.to));
      }
    }
  }
}

void solve(){
  // rep(i, N)cout << dist_go[i] << " ";
  // cout << endl;

  long long int money = 0;
  rep(i, N){
    int rest = T-(dist_go[i]+dist_back[i]);
    if(rest > 0)
      money = max(money, rest*A[i]);
  }
  printf("%lld\n", money);
}

int main(){
  scanf("%lld %lld %lld", &N, &M, &T);

  rep(i, N) scanf("%lld", &A[i]);
  rep(i, M){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    a--;b--;
    edge t;
    t.to = b;
    t.cost = c;
    path[a].push_back(t);
    t.to = a;
    path_r[b].push_back(t);
  }
  dijkstra(path, dist_go);
  dijkstra(path_r, dist_back);
  solve();
  return 0;
}