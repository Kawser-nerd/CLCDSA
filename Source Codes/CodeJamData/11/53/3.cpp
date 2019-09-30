#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define MAXV 10010
int parent[MAXV],rank[MAXV];

struct UnionFind{

	UnionFind(int n){
		int i;
		REP(i,n) {parent[i] = i; rank[i] = 1;}
	}

	int root(int x){
		if(parent[x] != x) parent[x] = root(parent[x]);
		return parent[x];
	}

	void connect(int x, int y){
		int rx=root(x),ry=root(y);
		if(rx == ry) return;
		if(rank[rx] > rank[ry]) {parent[ry] = rx; rank[rx] += rank[ry];}
		if(rank[rx] <= rank[ry]) {parent[rx] = ry; rank[ry] += rank[rx];}
	}
};

#define MOD 1000003

int X,Y;
string board[110];

int deg[10010];
pair <int, int> p[10010];
set <int> edge[10010];
bool used[10010];

int func(int N){
	int i,j;
	
	REP(i,N) used[i] = false;
	
	REP(i,N){
		int x = -1;
		REP(j,N) if(!used[j] && deg[j] <= 1) {x = j; break;}
		
		if(x == -1) break;
		
		if(deg[x] == 0) return 0;
		
		int e = *(edge[x].begin());
		int y = p[e].first + p[e].second - x;
		deg[x]--; deg[y]--;
		edge[x].erase(e); edge[y].erase(e);
		used[x] = true;
	}
	
	UnionFind uf(N);
	REP(i,N) if(!used[i]) foreach(edge[i],itr){
		int e = (*itr);
		uf.connect(p[e].first,p[e].second);
	}
	
	int ans = 1;
	REP(i,N) if(!used[i] && uf.root(i) == i) ans = ans * 2 % MOD;
	return ans;
}

void main2(void){
	int i,j,k;
	
	cin >> X >> Y;
	REP(i,X) cin >> board[i];
	int N = X*Y;
	
	REP(i,N) deg[i] = 0;
	REP(i,N) edge[i].clear();
	
	REP(i,X) REP(j,Y){
		int e = i * Y + j;
		
		int dx = 1, dy = 1;
		if(board[i][j] == '|') {dx = 1; dy = 0;}
		if(board[i][j] == '-') {dx = 0; dy = 1;}
		if(board[i][j] == '/') {dx = 1; dy = -1;}
		
		int xa = (i + dx + X) % X, ya = (j + dy + Y) % Y, a = xa * Y + ya;
		int xb = (i - dx + X) % X, yb = (j - dy + Y) % Y, b = xb * Y + yb;
		
		p[e] = make_pair(a,b);
		deg[a]++; deg[b]++;
		edge[a].insert(e); edge[b].insert(e);
		
	//	cout << a << ' ' << b << endl;
	}
	
	int ans = func(N);
	cout << ans << endl;
}

//////////////////////////////// multiple testcases ////////////////////////////////

int main(void){
	int T,t;
	scanf("%d",&T);
	REP(t,T){
		printf("Case #%d: ",t+1);
		main2();
	}
	return 0;
}
