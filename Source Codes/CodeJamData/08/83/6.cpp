#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<queue>

#define FOR(i,a,b) for(int i=(a); i<(int)(b); ++i)
#define FORD(i,a,b) for(int i=(a)-1; i>=(int)(b); --i)
#define FORE(i,C) for(__typeof(C.begin()) i=C.begin(); i!=C.end(); ++i)
#define MP make_pair
#define FI first
#define SE second
#define PB push_back

using namespace std;

typedef long long LL;

const int nMax = 505;
const int INF = 1000000009;

vector<int> tabN[nMax];
vector<int> child[nMax];
bool vis[nMax];
int N,K,res;

void dfs(int v) {
	vis[v] = true;
	FORE(it,tabN[v]) if(!vis[*it]) {
		vis[*it] = true;
		child[v].PB(*it);
		dfs(*it);
	}
}

void go(int v, int par, int gPar) {
	int left = K-par-gPar;
	int cur = child[v].size();
	FORE(it,child[v]) {
		res = (res*1LL*left)%INF;
		go(*it, cur, (par>0)?1:0);
		left--;
	}
}

void testcase(int tNum) {
	printf("Case #%d: ",tNum);
	
	scanf("%d %d",&N,&K);
	
	FOR(i,0,N) {
		tabN[i].clear();
		child[i].clear();
		vis[i] = false;
	}
	
	res = 1;
	FOR(i,0,N-1) {
		int a,b;
		scanf("%d %d",&a,&b); --a; --b;
		tabN[a].PB(b);
		tabN[b].PB(a);
	}
	
	dfs(0);
	
	go(0,0,0);
	
	FOR(i,0,N) {
		tabN[i].clear();
		child[i].clear();
		vis[i] = false;
	}
	
	printf("%d\n",res);
}

int main() {

	int t;
	scanf("%d",&t);
	FOR(i,0,t) testcase(i+1);
	
	return 0;
}
