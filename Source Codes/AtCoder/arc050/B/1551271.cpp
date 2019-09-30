#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <utility>
#include <memory>
#include <functional>
#include <deque>
#include <cctype>
#include <ctime>
#include <numeric>
#include <list>
#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <forward_list>

#define cauto const auto&
#else

#endif

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll;
typedef vector<vector<long long> > vvll;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}

#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _rep(i,n) _rep2((i),0,(n))
#define _rep2(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) GET_MACRO(__VA_ARGS__, _rep2, _rep)(__VA_ARGS__)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define fi first
#define se second
#define mkp make_pair
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif

#define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

ll R,B;
ll x,y;

ll func(ll mid){
	ll ret = mid;
	ll rr = R-x*mid;
	ll bb = B-mid;
	ret += min(rr, bb/y);
	return ret;
}


void mainmain(){
	cin>>R>>B;
	cin>>x>>y;
	ll l = 0, r = min(R/x, B);
	while(r-l>10){
		ll mid1 = l+(r-l)/3;
		ll mid2 = l+(r-l)/3*2;
		ll val1 = func(mid1);
		ll val2 = func(mid2);
		if(val1<val2){
			l = mid1;
		}
		else{
			r = mid2;
		}
	}
	ll ans = 0;
	for(ll i=l; i<r+1; i++){
		maxs(ans, func(i));
	}
	cout<<ans<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}