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
int m[1000];
int main(){
	int T;
	cin>>T;
	rep1(tt,T){
		int N;
		cin>>N;
		rep(i,N) cin>>m[i];
		int mx=0;
		int x=0,y=0;
		rep(i,N-1) x+=max(0,m[i]-m[i+1]);
		rep(i,N-1) chmax(mx,m[i]-m[i+1]);
		rep(i,N-1){
			int now=max(0,m[i]-mx);
			y+=m[i]-now;
		}
		printf("Case #%d: %d %d\n",tt,x,y);
	}
}
