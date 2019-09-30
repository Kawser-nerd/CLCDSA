#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

#define VV vector
#define PB push_back
#define ll long long
#define ld long double
#define REP(i,n) FOR(i,0,(n)-1)
#define FOR(i,a,b) for(int i = (a);i<=(b);++i)
#define FORD(i,a,b) for(int i = (a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define FOREACH(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SS(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define VI VV<int>
#define VS VV<string>
int COND = 1;
#define DB(x) { if (COND > 0) { COND--; REP (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

const int INF = 1000000001;
const int N=2600;
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
/*
 //Begin of the code
int main(){
  int n=4;
  REP(i,n) kraw[i].clear();
  REP(i,n) REP(j,n) c[i][j]=0;
  AddEdge(0,1,2);
  AddEdge(1,2,3);
  AddEdge(2,3,4);
  AddEdge(0,2,10);
  AddEdge(1,3,8);
  int res=Maxflow(0,3,n);
  printf("Maksymalny przeplyw wynosi %d\n",res);
  return 0;
}
*/


char X[101][101];
int A, B;

int MMM(){
    CLR(c, 0);
    CLR(dist, 0);
    CLR(X, 0);
    cin >> A >> B;
    int NN = A * B + 2;
    REP (i, A) REP (j, B) cin >> X[i][j];
    int ST = A * B;
    int ED = A * B + 1;
    REP(i,NN) kraw[i].clear();
    int ret1 = 0;

    REP (i, A) REP (j, B) {
        if (X[i][j] == '#' || X[i][j] == '?') {
            int cost = X[i][j] == '#' ? 100000 : 4;
            ret1 += 4;
            if ((i + j) % 2 == 0)
                AddEdge(ST, i * B + j, cost);
            else
                AddEdge(i * B + j, ED, cost);
        }
    }
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    REP (i, A) REP (j, B) {
        if ((i + j) % 2 == 0 && X[i][j] != '.') {
            REP (d, 4) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < A && nj >= 0 && nj < B && X[i][j] != '.') {
                    AddEdge(i * B + j, ni * B + nj, 2);
                }
            }

        }
    }
    int fl = Maxflow(ST, ED, NN);
    DB(ret1<<" "<<fl);
    return ret1 - fl;;
}

int main(int argc, char ** argv) { ios::sync_with_stdio(false);
    COND = argc >= 2 && argv[1][0] == 'q' ? (int)1e9 : 0;
    int T; cin >> T;
    FOR (my, 1, T) {
        DB(my);
        printf("Case #%d: %d\n", my, MMM());
    }

    return 0;
}
