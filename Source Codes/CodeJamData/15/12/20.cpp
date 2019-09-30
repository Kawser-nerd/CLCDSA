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
typedef long long ll;
int t[1000];
int main(){
	int T;
	cin>>T;
	rep1(tt,T){
		int B;
		ll N;
		cin>>B>>N;
		rep(i,B) cin>>t[i];
		ll ub=100000000000000,lb=-1;	//1e14
		while(ub-lb>1){
			ll m=(ub+lb)/2;
			ll s=0;
			rep(i,B){
				s+=m/t[i]+1;
			}
			if(s>=N) ub=m;
			else lb=m;
		}
		ll m=ub,s=0;
//		show(m);
		vector<int> justs;
		rep(i,B){
			s+=(m+t[i]-1)/t[i];
			if(m%t[i]==0) justs.pb(i);
		}
//		show(s);
		N-=s;
		printf("Case #%d: %d\n",tt,justs[N-1]+1);
	}
}
