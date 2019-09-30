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
#define F_INF 10000
#define MAXV 20000
#define MAXE 50000 // E*2!

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

char buf[20000];

int N,W; // N <= 200, W <= 4000
vector <string> v[210];
map <string, int> mp;

void main2(void){
	int i,j;
	
	cin >> N; gets(buf);
	REP(i,N) v[i].clear();
	REP(i,N){
		gets(buf);
		string s = buf;
		istringstream ss(s);
		while(ss >> s) v[i].push_back(s);
	}
	
	mp.clear();
	REP(i,N) REP(j,v[i].size()) mp[v[i][j]] = 0;
	W = 0;
	snuke(mp,itr){
		(itr->second) = W;
		W++;
	}
	
	MaxFlow mf(2*N+2*W);
	REP(i,N) mf.add_edge(2*i, 2*i+1, 10000);
	REP(i,W) mf.add_edge(2*(N+i), 2*(N+i)+1, 1);
	REP(i,N) REP(j,v[i].size()){
		int id = mp[v[i][j]];
		mf.add_edge(2*i+1, 2*(N+id), 10000);
		mf.add_edge(2*(N+id)+1, 2*i, 10000);
	}
	
	int ans = mf.maxflow(0, 3);
	cout << ans << endl;
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
