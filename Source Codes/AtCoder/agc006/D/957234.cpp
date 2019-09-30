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

const int N=201000;
int p[N],q[N],n;
bool check(int x) {
	rep(i,1,2*n) if (p[i]>=x) q[i]=1; else q[i]=0;
	int pr=1;
//	rep(i,1,2*n) printf("%d",q[i]);
//	puts("");
	rep(i,2,2*n+1) {
		if (q[i]==q[i-1]||i==2*n) {
			if (pr==i-1) pr=i;
			else {
				if (q[pr]==q[i-1]) {
					rep(j,pr,i) q[j]=q[pr];
				} else {
					int md=(pr+i)/2;
					rep(j,pr,md) q[j]=q[pr];
					rep(j,md,i) q[j]=q[i-1];
				}
				pr=i;
			}
		}
	}
//	rep(i,1,2*n) printf("%d",q[i]);
//	puts("");
	return q[n];
}
int main() {
	scanf("%d",&n);
	rep(i,1,2*n) scanf("%d",p+i);
	int l=0,r=2*n-1;
	while (l+1<r) {
		int md=(l+r)>>1;
		if (check(md)==0) r=md; else l=md;
	}
	printf("%d\n",l);
}