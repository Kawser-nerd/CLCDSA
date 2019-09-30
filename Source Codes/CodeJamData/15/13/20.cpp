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
typedef double D;
typedef complex<D> P;
D inf=1e50,eps=1e-9,PI=acos(0.0)*2;
P p[3000];
int main(){
	int T;
	cin>>T;
	rep1(tt,T){
		printf("Case #%d:\n",tt);
		int N;
		cin>>N;
		rep(i,N){
			int x,y;
			cin>>x>>y;
			p[i]=P(x,y);
		}
		rep(i,N){
			vector<D> as;
			rep(j,N) if(j!=i) as.pb(arg(p[j]-p[i]));
			sort(all(as));
			rep(j,N-1) as.pb(as[j]+PI*2);
			int k=0,mx=0;
			rep(j,N-1){
				while(as[j]+PI+eps>as[k]) k++;
				chmax(mx,k-j);
			}
			cout<<N-1-mx<<endl;
		}
	}
}
