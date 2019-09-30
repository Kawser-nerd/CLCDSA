#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
//???????????????????
//????10^5?????2×10^5????????????????????????????
//???????????????????????
//?????
lint gcd( lint m, lint n )
{
	lint a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}

//?????
//?????????long long???????
lint lcm( lint m, lint n )
{
	if (( 0 == m ) || ( 0 == n )) return 0;
	return ((m / gcd(m, n)) * n);
}
vector<lint> so;
bool sos[10010];
lint out[510][510];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
map<lint,int> me;
set<lint> se;
int main()
{
	lint inf=1000000000000000LL;
	memset(sos,false,sizeof(sos));
	REP(i,2,10010){
		if(sos[i]) continue;
		for(int j=i+i;j<10010;j+=i) sos[j]=true;
		if(i>501 && so.size()<510) so.pb(i);
	}
	rep(i,500) rep(j,500){
		if((i+j)%2==0) continue;
		out[i][j]=so[i/2]*(j+2);
		se.insert(out[i][j]-1);
	}
	rep(i,500) rep(j,500){
		if((i+j)%2==1) continue;
		out[i][j]=1;
		if(i>0) out[i][j]*=so[(i-1)/2];
		if(i<499) out[i][j]*=so[(i+1)/2];
		for(int k=max(0,j-1);k<min(500,j+2);k++) out[i][j]*=(k+2);
		lint t=1;
		while(se.find(out[i][j]*t)!=se.end()) t++;
		out[i][j]*=t;
		se.insert(out[i][j]);
		out[i][j]++;
	}
	rep(i,500) rep(j,500){
		assert(out[i][j]<=inf);
		if(out[i][j]>=inf){
			cout<<out[i][j]<<endl;
		}
		//assert(!me[out[i][j]]);
		if(me[out[i][j]]>0){
			cout<<out[i][j]<<' '<<i<<' '<<j<<' '<<me[out[i][j]]<<endl;
		}
		me[out[i][j]]++;
		rep(k,4){
			int x=i+dx[k],y=j+dy[k];
			if(x<0 || y<0 || x>499 || y>499) continue;
			lint a=max(out[i][j],out[x][y]),b=min(out[i][j],out[x][y]);
			if(a%b!=1LL){
				cout<<i<<' '<<j<<' '<<x<<' '<<y<<' '<<a<<' '<<b<<' '<<a%b<<endl;
			}
		}
	}
	int n;cin>>n;
	rep(i,n){
		rep(j,n){
			cout<<out[i][j];
			if(j<n-1) cout<<' ';else cout<<endl;
		}
	}
}