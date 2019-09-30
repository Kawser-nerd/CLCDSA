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


string go(string s) {
	int n=(int)s.size();
	int i;
	for(i=0;i+1<n;i++) {
		if(s[i] > s[i+1]) goto qq;
	}
	return s;
	qq:;
	for(int j=i+1;j<n;j++) s[j]='9';
	for(;s[i]=='0' || (i&&s[i]==s[i-1]);) s[i]='9', --i;
	--s[i];
	for(;s[0]=='0';) s=s.substr(1);
	return s;
}
void go(int tn) {
	string s; cin>>s;
	string Z=go(s);
	printf("Case #%d: ",tn);
	cout<<Z<<endl;
}




int32_t main() {
	int T; scanf("%d",&T); for(int i=1;i<=T;i++) {
		go(i);
	}
}