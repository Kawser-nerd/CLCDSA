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
	int x1,y1,r,x2,y2,x3,y3;
	cin>>x1>>y1>>r>>x2>>y2>>x3>>y3;
	if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)<=r*r&&(x2-x1)*(x2-x1)+(y3-y1)*(y3-y1)<=r*r&&(x3-x1)*(x3-x1)+(y2-y1)*(y2-y1)<=r*r&&(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)<=r*r) {
		cout<<"YES"<<endl;
		cout<<"NO"<<endl;
		return 0;
	}
	if(x1>=x2&&x1<=x3&&y1>=y2&&y1<=y3&&x1-x2>=r&&x3-x1>=r&&y1-y2>=r&&y3-y1>=r) {
		cout<<"NO"<<endl;
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	cout<<"YES"<<endl;
	return 0;
}