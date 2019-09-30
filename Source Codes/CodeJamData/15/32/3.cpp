#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=110;
int _,__,k,l,s,cnt[N],nxt[N],dp[N][N],go[N][N];
char kb[N],tg[N];
void kmp(char *s2,int l2) {
	nxt[0]=-1;
	int k=-1;
	rep(i,1,l2) {
		while (k>=0&&s2[k+1]!=s2[i]) k=nxt[k];
		if (s2[k+1]==s2[i]) ++k;
		nxt[i]=k;
	}
}

int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d%d",&k,&l,&s);
		scanf("%s",kb);
		rep(i,0,26) cnt[i]=0;
		rep(i,0,k) cnt[kb[i]-'A']++;
		scanf("%s",tg);
		bool fg=0;
		rep(i,0,l) {
			if (cnt[tg[i]-'A']==0) {
				fg=1;
				break;
			}
		}
		if (fg) {
			printf("Case #%d: 0\n",++__);
			continue;
		}
		kmp(tg,l);
		int p=-1,ret=0;
		rep(i,0,s) {
			p++;
			if (p==l-1) ret++,p=nxt[p];	
		}
		double prob=1;
		rep(j,0,l) prob*=1.*cnt[tg[j]-'A']/k;
		printf("Case #%d: %.10f\n",++__,ret-(prob)*(s-l+1));
	}
}
