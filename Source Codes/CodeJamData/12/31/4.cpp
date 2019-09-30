#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
vector<int> g[1005];
int flag;
int used[1005];
void dfs(int v){
	used[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(!used[to]) dfs(to);
		else flag=1;
	}
}
int main(){
	int t;scanf("%d",&t);
	REP(setn,t){
		int n;scanf("%d",&n);
		flag=0;
		REP(i,n){
			g[i].clear();
			int m;scanf("%d",&m);
			g[i].resize(m);
			REP(j,m){
				scanf("%d",&g[i][j]);
				--g[i][j];
			}
		}
		printf("Case #%d: ",setn+1);
		REP(i,n){
			memset(used,0,sizeof(used));
			dfs(i);
		}

		if(flag) puts("Yes");
		else puts("No");
	}

	return 0;
}



