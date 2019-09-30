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
//#include <utility>
//#include <memory>
//#include <functional>
//#include <deque>
//#include <cctype>
//#include <ctime>
//#include <numeric>
//#include <list>
//#include <iomanip>

//#if __cplusplus >= 201103L
//#include <array>
//#include <tuple>
//#include <initializer_list>
//#include <forward_list>
//
//#define cauto const auto&
//#else

//#endif

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

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

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif

// #define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

ll MOD;

struct mint{
    ll x;
    mint():x(0){}
    mint(ll x):x((x%MOD+MOD)%MOD){}
    mint operator+=(const mint& a){ if((x+=a.x)>=MOD) x-=MOD; return *this;}
    mint operator-=(const mint& a){ if((x+=MOD-a.x)>=MOD) x-=MOD; return *this;}
    mint operator*=(const mint& a){ (x*=a.x)%=MOD; return *this;}
    mint operator+(const mint& a)const{ return mint(*this) += a;}
    mint operator-(const mint& a)const{ return mint(*this) -= a;}
    mint operator*(const mint& a)const{ return mint(*this) *= a;}
    bool operator==(const mint& a)const{ return x == a.x;}
};
//
// Matrix
struct mat{
    typedef mint TT;
    int h, w;
    vector<vector<TT> > d;
    mat(){}
    mat(int h, int w, TT v=0):h(h),w(w),d(h,vector<TT>(w,v)){}
    void fil(TT v=0){ rep(i,h)rep(j,w) d[i][j] = v;}
    void uni(){ rep(i,h)rep(j,w) d[i][j] = (i==j);}
    mat operator*(const mat& a)const{ // w = a.h
        mat res(h,a.w);
        rep(i,h)rep(k,w)rep(j,a.w) res.d[i][j] += d[i][k]*a.d[k][j];
        return res;
    }
    mat power(ll a){ // h = w
        if(a == 0){
            mat res(h,w); res.uni();
            return res;
        }
        mat res = power(a/2);
        res = res*res;
        if(a&1) res = res*(*this);
        return res;
    }
};


/*
 10 1
 0  1

*/

mint __pow(ll a,ll b){
	mint ret(1LL);
	mint c(a);
	while(b){
		if(b&1) ret*=c;
		b>>=1;
		c*=c;
	}
	return ret;
}

void mainmain(){
	ll a, b;
	cin >> a >> b;
	cin >> MOD;
	ll c = __gcd(a, b);
	mat aa(2,1,1);
	mat cc(2,2);
	cc.d[0][0] = mint(10);
	cc.d[0][1] = mint(1);
	cc.d[1][0] = mint(0);
	cc.d[1][1] = mint(1);
	aa = cc.power(a-1) * aa;
	mat bb(2,1,1);
	cc.d[0][0] = __pow(10,c);
	bb = cc.power(b/c-1) * bb;
	ll ans = aa.d[0][0].x * bb.d[0][0].x;
	cout << ans % MOD << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}