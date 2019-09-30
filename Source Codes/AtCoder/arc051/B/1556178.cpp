#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8
#define REP(i,m) for(long long i=0; i<m; ++i)
#define FOR(i,n,m) for(long long i=n; i<m; ++i)
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<long long> vl;
typedef vector<vector<long long> > vll;
typedef vector<P> vp;
typedef vector<vector<P> > vpp;

int main() {
	ios::sync_with_stdio(false);
	int k;
	cin>>k;
	ll a=2,b=1;
	REP(i,k-1) {
		ll buf1=a+b,buf2=a;
		a=buf1;b=buf2;
	}
	cout<<a<<" "<<b<<endl;
}