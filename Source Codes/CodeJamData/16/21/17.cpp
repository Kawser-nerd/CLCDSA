#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <string>
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

string dig[]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
// Z
// 
VI p[70];
int vis[70],_,__,n,cnt[70],ret[70];
char s[2010];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%s",s);
		n=strlen(s);
		rep(i,0,26) cnt[i]=0;
		rep(i,0,n) cnt[s[i]-'A']++;
		rep(i,0,10) vis[i]=0;
		rep(i,0,10) {
			rep(j,0,26) p[j].clear();
			rep(j,0,10) if (!vis[j]) {
				rep(k,0,SZ(dig[j])) p[dig[j][k]-'A'].pb(j);
			}
			rep(j,0,26) if (SZ(p[j])==1) {
				int num=p[j][0];
				ret[num]=cnt[j];
				rep(j,0,SZ(dig[num])) cnt[dig[num][j]-'A']-=ret[num];
//				printf("%c %d %d\n",j+'A',num,ret[num]);
				vis[num]=1;
				break;
			}
		}
		printf("Case #%d: ",++__);
		rep(j,0,10) rep(k,0,ret[j]) printf("%d",j);
		puts("");

	}
}
