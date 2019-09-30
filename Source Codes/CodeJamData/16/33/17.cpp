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
int A,B,C,K,T;
int x[10][10][10];
void ans(int i,int j,int k){
	printf("%d %d %d\n",i,j,k);
	x[i-1][j-1][k-1]=1;
}
bool isok(){
	rep(i,A) rep(j,B){
		int c=0;
		rep(k,C) c+=x[i][j][k];
		if(c>K) return 0;
	}
	rep(i,A) rep(k,C){
		int c=0;
		rep(j,B) c+=x[i][j][k];
		if(c>K) return 0;
	}
	rep(j,B) rep(k,C){
		int c=0;
		rep(i,A) c+=x[i][j][k];
		if(c>K) return 0;
	}
	return 1;
}
int main(){
	cin>>T;
	rep1(tt,T){
		rep(i,10) rep(j,10) rep(k,10) x[i][j][k]=0;
		cin>>A>>B>>C>>K;
		printf("Case #%d: ",tt);
		cout<<min(K,C)*A*B<<endl;
		if(K>=C){
			rep1(i,A) rep1(j,B) rep1(k,C) ans(i,j,k);
			continue;
		}
		rep(i,A) rep(j,B){
			rep(k,K) ans(i+1,j+1,(i+j+k)%C+1);
		}
		assert(isok());
	}
}
