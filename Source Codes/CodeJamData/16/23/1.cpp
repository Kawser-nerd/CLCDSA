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
#define MAXV 10000
#define MAXE 10000 // E*2!

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

map <string, int> mp1,mp2;
string sl[1010],sr[1010];
int l[1010],r[1010];

void main2(void){
	int i;
	
	mp1.clear();
	mp2.clear();
	
	int L = 0, R = 0;
	int N;
	cin >> N;
	REP(i,N) cin >> sl[i] >> sr[i];
	
	REP(i,N) mp1[sl[i]] = 0;
	REP(i,N) mp2[sr[i]] = 0;
	
	snuke(mp1,itr){
		(itr->second) = L;
		L++;
	}
	
	snuke(mp2,itr){
		(itr->second) = R;
		R++;
	}
	
	REP(i,N) l[i] = mp1[sl[i]];
	REP(i,N) r[i] = mp2[sr[i]];
	
	MaxFlow mf(L+R+2);
	REP(i,L) mf.add_edge(L+R, i, 1);
	REP(i,R) mf.add_edge(L+i, L+R+1, 1);
	REP(i,N) mf.add_edge(l[i], L+r[i], 1);
	
	int f = mf.maxflow(L+R, L+R+1);
	int tmp = L + R - f;
	int ans = N - tmp;
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
