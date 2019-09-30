#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <iostream>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

string s[40][4];
int cs[40][4],cr[40][4],cp[40][4];
int _,n,R,P,S,__;
int main() {
	s[0][0]='R';
	s[0][1]='P';
	s[0][2]='S';
	rep(i,1,13) {
		s[i][0]=min(s[i-1][0]+s[i-1][2],s[i-1][2]+s[i-1][0]);
		s[i][1]=min(s[i-1][0]+s[i-1][1],s[i-1][1]+s[i-1][0]);
		s[i][2]=min(s[i-1][1]+s[i-1][2],s[i-1][2]+s[i-1][1]);
		rep(j,0,3) {
			rep(k,0,SZ(s[i][j])) {
				if (s[i][j][k]=='R') cr[i][j]++;
				else if (s[i][j][k]=='P') cp[i][j]++;
				else cs[i][j]++;
			}
//			printf("%d %d %d\n",cr[i][j],cp[i][j],cs[i][j]);
		}
	}
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		scanf("%d%d%d",&R,&P,&S);
		printf("Case #%d: ",++__);
		int val=0;
		rep(j,0,3) if (cs[n][j]==S&&cp[n][j]==P&&cr[n][j]==R) {
			cout<<s[n][j]<<endl;
			val++;
		}
		if (!val) puts("IMPOSSIBLE");
//		dfs(n,r,p,s);
	}
}
