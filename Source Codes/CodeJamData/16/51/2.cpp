#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <stack>
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
int n;
char s[20100];
int main() {
	for (scanf("%d",&_);_;_--) {
		printf("Case #%d: ",++__);
		scanf("%s",s);
		n=strlen(s);
		stack<char> st;
		int ret=0;
		rep(i,0,n) {
			if (st.empty()||s[i]!=st.top()) st.push(s[i]);
			else st.pop(),ret+=10;
		}
		ret+=SZ(st)/2*5;
		printf("%d\n",ret);
	}
}
