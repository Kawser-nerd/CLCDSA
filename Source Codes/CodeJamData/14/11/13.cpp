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


int n,l;
lint source[155],need[155];

lint flipped[155];
int main(){
	int t;cin>>t;
	REP(setn,t){
		printf("Case #%d: ",setn+1);
		cin>>n>>l;

		REP(i,n){
			lint bit=0;
			char tmp[55];scanf("%s",tmp);
			REP(j,l) if(tmp[j]=='1') bit|=(1ll<<j);
			source[i]=bit;
		}
		REP(i,n){
			lint bit=0;
			char tmp[55];scanf("%s",tmp);
			REP(j,l) if(tmp[j]=='1') bit|=(1ll<<j);
			need[i]=bit;
		}
		sort(need,need+n);

		int res=INF;
		REP(i,n){
			lint shift=(source[0]^need[i]);
			REP(j,n) flipped[j]=(source[j]^shift);
			sort(flipped,flipped+n);
			int fail=0;
			REP(j,n) if(flipped[j]!=need[j]) fail=1;
			if(!fail) res=min(res,__builtin_popcountll(shift));
		}
		if(res==INF) puts("NOT POSSIBLE");
		else printf("%d\n",res);
	}

	return 0;
}



