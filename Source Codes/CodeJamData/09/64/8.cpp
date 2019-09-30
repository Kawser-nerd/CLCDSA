#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
#include <cstring>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()


const int INF = 1000000001;
const int N=1100;
VI kraw[N];
VI::iterator begin[N];
int c[N][N];
int dist[N];

void AddEdge(int a,int b,int cc){
	c[a][b]+=cc;
	kraw[a].PB(b);
	kraw[b].PB(a);
}
int q[N];

int bfs(int s,int t,int n){
	REP(i,n) dist[i]=-1;
	dist[s]=0;
	int beg=0,end=0;
	q[end++]=s;
	while (beg<end){
		int v=q[beg++];
		FOREACH(it,kraw[v]) if (c[v][*it]>0 && dist[*it]==-1){
			dist[*it]=dist[v]+1;
			q[end++]=*it;
		}
	}	
	return dist[t]!=-1;
}

int dfs(int x,int t,int minimum){
	int res=0;
	if (x==t || minimum==0) return minimum;
	for(VI::iterator &it=begin[x];it!=kraw[x].end(); ++it){
		if (dist[x]+1==dist[*it] && c[x][*it]>0){
			int y=dfs(*it,t,min(minimum,c[x][*it]));
			c[x][*it]-=y;
			c[*it][x]+=y;
			minimum-=y;
			res+=y;
			if (minimum==0) break;
		}
	}
	return res;
}

int Maxflow(int s,int t,int n){
	int res=0;
	while (bfs(s,t,n)){
		REP(i,n) begin[i]=kraw[i].begin();
		res+=dfs(s,t,INF);
	}
	return res;
}

void init(int n){
	REP(i,n) kraw[i].clear();
	REP(i,n) REP(j,n) c[i][j] = 0;
}

inline int sqr(int x){return x*x;}


int x[N], y[N], r[N], s[N];

int main(){
  int testy;
  scanf("%d",&testy);
  REP(numer_testu,testy){
    printf("Case #%d: ", numer_testu+1);
		int n;
		scanf("%d",&n);
		int wierzcholki = n+2;
		init(wierzcholki);
		
		REP(i,n){
			scanf("%d %d %d %d",x+i,y+i,r+i,s+i);
		}
		REP(i,n) if (s[i] > 0){
			AddEdge(0, i+1, s[i]);
		} else if (s[i] < 0){
			AddEdge(i+1, wierzcholki-1, -s[i]);
		}
		REP(i,n) REP(j,n) if (i!=j && sqr(x[i]-x[j]) + sqr(y[i]-y[j]) <= sqr(r[i])){
			AddEdge(i+1,j+1, INF);
		}
		fflush(stdout);
		
		int res = 0;
		REP(i,n) if (s[i] > 0) res += s[i];
		printf("%d\n",res - Maxflow(0, wierzcholki-1, wierzcholki));
  }
  return 0;
}
