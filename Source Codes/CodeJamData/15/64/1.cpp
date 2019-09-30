#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef int F;
#define F_INF (1<<29)
#define MAXV 210
#define MAXE 100000 // E*2!

F cap[MAXE],flow[MAXE];
int to[MAXE],prev[MAXE],last[MAXV],used[MAXV],level[MAXV];

struct MaxFlow{
	int V,E;

	MaxFlow(int n){
		int i;
		V = n; E = 0;
		REP(i,V) last[i] = -1;
	}

	void add_edge(int x, int y, F f){
		cap[E] = f; flow[E] = 0; to[E] = y; prev[E] = last[x]; last[x] = E; E++;
		cap[E] = 0; flow[E] = 0; to[E] = x; prev[E] = last[y]; last[y] = E; E++;
	}

	bool bfs(int s, int t){
		int i;
		REP(i,V) level[i] = -1;
		queue <int> q;
		q.push(s); level[s] = 0;
		while(!q.empty()){
			int x = q.front(); q.pop();
			for(i=last[x];i>=0;i=prev[i]) if(level[to[i]] == -1 && cap[i] > flow[i]) {q.push(to[i]); level[to[i]] = level[x] + 1;}
		}
		return (level[t] != -1);
	}

	F dfs(int v, int t, F f){
		int i;
		if(v == t) return f;
		for(i=used[v];i>=0;used[v]=i=prev[i]) if(level[to[i]] > level[v] && cap[i] > flow[i]){
			F tmp = dfs(to[i],t,min(f,cap[i]-flow[i]));
			if(tmp > 0) {flow[i] += tmp; flow[i^1] -= tmp; return tmp;}
		}
		return 0;
	}

	F maxflow(int s, int t){
		int i;
		while(bfs(s,t)){
			REP(i,V) used[i] = last[i];
			while(dfs(s,t,F_INF) != 0);
		}
		F ans = 0;
		for(i=last[s];i>=0;i=prev[i]) ans += flow[i];
		return ans;
	}

};

#define INF (1<<29)

int N;
int dist[110][110];
bool middle[110];
	
void main2(void){
	int M,K,i,j,k;
	
	cin >> N >> M >> K;
	REP(i,N) REP(j,N) if(i != j) dist[i][j] = INF;
	REP(i,M){
		int s,t;
		cin >> s >> t;
		dist[s][t] = dist[t][s] = 1;
	}
	
	REP(k,N) REP(i,N) REP(j,N) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int D = dist[0][N-1];
	
	REP(i,N) middle[i] = false;
	REP(i,N) if(dist[0][i] + dist[i][N-1] == dist[0][N-1]) middle[i] = true;
	
	MaxFlow mf(2*N);
	REP(i,N) mf.add_edge(2*i, 2*i+1, 1);
	REP(i,N) REP(j,N) if(dist[i][j] == 1 && dist[0][i] < dist[0][j] && middle[i] && middle[j]) mf.add_edge(2*i+1, 2*j, 110);
	
	int f = mf.maxflow(1, 2*N-2);
	if(f + 1 <= K) cout << D + 2 << endl; else cout << D + 1 << endl;
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
