#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cctype>
#include <cassert>

using namespace std;

typedef double D;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<D> vd;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back

template<typename T> T abs(T x) { return (x>0) ? x : -x; }
template<typename T> T sqr(T x) { return x*x;            }

const int max_n=500+218;

const ll mod=1000000009;
int n;
ll k;
ll deg[max_n];
vi g[max_n];

ll getAm(int n, int k) {
	if (n<k) return 0;
	ll res=1;
	for (int i=0; i<k; i++)
		res=(res*(n-i))%mod;
	return res;
}

ll solve(int v, int from) {
	vll ans;
	for (int i=0; i<sz(g[v]); i++) {
		int w=g[v][i];
		if (w==from) continue;
		ans.pb(solve(w,v));
	}
	ll res=1;
	for (int i=0; i<sz(ans); i++)
		res=(res*ans[i])%mod;
	int use=k-deg[from];
	if (use<0)
		use=0;
	int need=deg[v];
	if (v!=1)
		need--;
	res=(res*getAm(use,need))%mod;
	return res;
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	int tn;
	cin>>tn;
	for (int tst=0; tst<tn; tst++) {
		printf("Case #%d: ",tst+1);
		cin>>n>>k;
		for (int i=0; i<=n; i++)
			g[i].clear(), deg[i]=0;
		for (int i=0; i<n-1; i++) {
			int a,b;
			cin>>a>>b;
			deg[a]++;
			deg[b]++;
			g[a].pb(b);
			g[b].pb(a);
		}
		cout<<solve(1,0)<<endl;
	}

	return 0;
}
