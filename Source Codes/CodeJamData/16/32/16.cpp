#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
int T;
int N;
ll K;
int ans[50][50];
bool B(ll x,int i){return (x>>i)&1;}
int main(){
	cin>>T;
	rep1(tt,T){
		cin>>N>>K;
		rep(i,N) rep(j,N) ans[i][j]=0;
		printf("Case #%d: ",tt);
		ll p2=1;
		rep(i,N-2) p2*=2;
		if(p2<K){
			puts("IMPOSSIBLE");
			continue;
		}
		puts("POSSIBLE");
		int k=0;
		ll p=1;
		while(p<K) p*=2,k++;
		rep(i,k+1) for(int j=i+1;j<k+1;j++) ans[i][j]=1;
		if(p==K) ans[0][N-1]=1;
		rep(i,k){
			if(p==K||B(K,i)) ans[i+1][N-1]=1;
		}
		rep(i,N){
			rep(j,N) cout<<ans[i][j];
			puts("");
		}
	}
}
