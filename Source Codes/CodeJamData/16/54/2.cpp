#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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

int _,__;
int n,l;
char s[110][55],t[55];
int main() {
	for (scanf("%d",&_);_;_--) {
		printf("Case #%d: ",++__);
		scanf("%d%d",&n,&l);
		rep(i,0,n) scanf("%s",s[i]);
		scanf("%s",t);
		bool val=1;
		rep(i,0,n) {
			if (strcmp(s[i],t)==0) val=0;
		}
		if (val==0) {
			puts("IMPOSSIBLE");
			continue;
		}
		if (l==1) {
			if (t[0]=='1') puts("0 0?");
			else puts("1 1?");
			continue;
		}
		rep(i,0,l-1) if (t[i]=='0') printf("10"); else printf("01");
		printf(" ");
		rep(i,0,l) {
			if (t[i]=='1') printf("0"); else printf("1");
			printf("?");
		}
		puts("");
	}
}
