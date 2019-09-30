#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int n;
vector<int> g[1005];
int size[1005];
int prep(int v,int p){
	size[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		size[v]+=prep(to,v);
	}
	return size[v];
}

int dfs(int v,int p){
	int tot=0;
	vector<int> cost;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		int C=dfs(to,v);
		tot+=size[to];
		cost.pb(C-size[to]);
	}
	sort(ALL(cost));
	if(cost.size()==0) return 0;
	if(cost.size()==1) return tot;
	return min(tot,tot+cost[0]+cost[1]);
}

int main(){
	int t;
	cin>>t;
	REP(setn,t){
		printf("Case #%d: ",setn+1);
		
		cin>>n;
		REP(i,n) g[i].clear();
		REP(i,n-1){
			int a,b;cin>>a>>b;--a;--b;
			g[a].pb(b);
			g[b].pb(a);
		}
		
		int res=INF;
		REP(i,n){

			prep(i,-1);

			int tmp=dfs(i,-1);
			chmin(res,tmp);
		}
		printf("%d\n",res);
	}
	return 0;
}



