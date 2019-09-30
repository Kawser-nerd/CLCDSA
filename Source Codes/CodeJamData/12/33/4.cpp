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
lint dp[105][105];
pair<int,lint> toy[105],box[105];
int n,m;
bool judge(const pair<int,lint>& a){
	return a.fr==-1;
}
void dfs(int i,int j,lint rest1,lint rest2,lint cur){
	dp[i+1][j+1]=max(dp[i+1][j+1],cur);
	if(rest1==0 && rest2==0) return;
	if(rest1==0){
		for(int k=i+1;k<n;++k) if(box[k].fr==toy[j].fr){
			lint mini=min(box[k].sc,rest2);
			dfs(k,j,box[k].sc-mini,rest2-mini,cur+mini);
			break;
		}
	}else{
		for(int k=j+1;k<m;++k) if(toy[k].fr==box[i].fr){
			lint mini=min(toy[k].sc,rest1);
			dfs(i,k,rest1-mini,toy[k].sc-mini,cur+mini);
			break;
		}
	}
}
	
int main(){
	int t;scanf("%d",&t);
	REP(setn,t){
		printf("Case #%d: ",setn+1);
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&m);
		REP(i,n){
			scanf("%lld%d",&box[i].sc,&box[i].fr);
		}
		REP(i,m) scanf("%lld%d",&toy[i].sc,&toy[i].fr);
		REP(i,n){
			int j=i+1;
			while(j<n && box[i].fr==box[j].fr){
				box[i].sc+=box[j].sc;
				box[j].fr=-1;
				++j;
			}
			i=j-1;
		}

		REP(i,m){
			int j=i+1;
			while(j<m && toy[i].fr==toy[j].fr){
				toy[i].sc+=toy[j].sc;
				toy[j].fr=-1;
				++j;
			}
			i=j-1;
		}
		n=remove_if(box,box+n,judge)-box;
		m=remove_if(toy,toy+m,judge)-toy;

		REP(i,n+1) REP(j,m+1){
			if(i<n && j<m && box[i].fr==toy[j].fr){
				lint mini=min(box[i].sc,toy[j].sc);
				dfs(i,j,box[i].sc-mini,toy[j].sc-mini,mini+dp[i][j]);
			}else{
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
				dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
			}
		}
		printf("%lld\n",dp[n][m]);
	}

	return 0;
}



