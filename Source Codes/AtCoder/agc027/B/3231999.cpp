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
lint x[200100],sum[200100];
lint inf=123456789012345678;
lint mul(lint a,lint b){
	if(a==0LL) return 0LL;
	if(inf/a+1<b) return inf;return a*b;
}
int main()
{
	int n;lint X,out=inf;
	cin>>n>>X;
	rep(i,n) cin>>x[i];
	sum[0]=0;rep(i,n) sum[i+1]=sum[i]+x[i];
	REP(i,1,n+1){
		lint now=i*X;
		REP(j,1,n/i+2){
			int hi=max(0,n-j*i+i),lo=max(0,n-j*i);
			now+=mul(sum[hi]-sum[lo],max(5,j*2+1));
			now=min(now,inf);
		}
		//cout<<i<<' '<<now<<endl;
		out=min(out,now);
	}
	cout<<out+n*X<<endl;
}