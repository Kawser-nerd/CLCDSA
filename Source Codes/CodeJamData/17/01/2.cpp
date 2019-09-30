// '
#include <bits/stdc++.h>
// #include <bits/extc++.h>
using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld TAU=2*acos(-1);
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;


void flip(char &c) {
	if(c=='-') c='+'; else
	if(c=='+') c='-'; else
	assert(0);
}
void flip(string &s,int L,int R) {
	for(int i=L;i<=R;i++) flip(s[i]);
}
bool gg(string s) {
	for(char c:s) if(c=='-') return 0;
	return 1;
}
void go(int tn) {
	string S; cin>>S;
	int k; cin>>k;
	int n=(int)S.size();
	assert(k<=n);
	int Z=0;
	for(int i=n-1;i>=k-1;i--) {
		if(S[i]=='-') flip(S,i-k+1,i), ++Z;
	}
	int ans=Z;
	if(gg(S)) printf("Case #%d: %d\n",tn,ans);
	else printf("Case #%d: IMPOSSIBLE\n",tn);
}




int32_t main() {
	int T; scanf("%d",&T); for(int i=1;i<=T;i++) {
		go(i);
	}
}