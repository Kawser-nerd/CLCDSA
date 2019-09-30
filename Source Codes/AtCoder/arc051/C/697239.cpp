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

#define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

typedef __int128 ull;
typedef pair<ull,int> P;

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
ll powmod(ll x,ll y){
	ll a=1;
	while(y){
		if(y&1) a=a*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return a;
}

void mainmain(){
	int n;
	ll A,B;
	cin>>n>>A>>B;
	vector<ull> v(n);
	int t;
	rep(i,n) cin>>t,v[i]=t;
	sort(ALL(v));
	if(A==1){
		rep(i,n){
			int t;
			t=v[i];
			cout<<t<<endl;;
		}
		return;
	}
	priority_queue<P,vector<P >,greater<P> > pq;
	rep(i,n){
		pq.push(P(v[i],0));
	}
	int cnt = 0;
	while(B){
		B--;
		P top = pq.top();
		pq.pop();
		if(top.S==0) cnt++;
		// cout<<ll(top.F)<<" "<<ll(top.S)<<" "<<cnt<<endl;
		top.F*=A;
		top.S++;
		pq.push(top);
		if(cnt==n) break;
	}	
	if(!B){
		rep(i,n){
			auto top = pq.top();
			pq.pop();
			cout<<ll(top.F)%MOD<<endl;
		}
		return;
	}
	vector<P> w(n);
	rep(i,n){
		w[i] = pq.top();
		// cout<<ll(w[i].F)<<endl;
		pq.pop();
	}
	rep(i,n) w[i].F/=A,w[i].S=0;
	rep(i,n) pq.push(w[i]);
	ull BB = 0;
	cnt = 0;
	// cout<<"-----------------"<<endl;
	cnt = B/n;
	B%=n;
	while(B){
		B--;
		BB++;
		P top = pq.top();
		pq.pop();
		// if(top.S==0) cnt++;
		// cout<<top.F<<" "<<top.S<<endl;
		top.F*=A;
		top.S++;
		pq.push(top);
		// if(cnt==n) break;
	}
	rep(i,n){
		auto top = pq.top();
		pq.pop();
		ll t = top.F%MOD;
		cout<<t*powmod(A,cnt+1)%MOD<<endl;
	}
	return;
	// cout<<BB<<endl;
	// rep(i,n){
	// 	w[i]=pq.top();
	// 	w[i].F/=A;
	// 	w[i].S--;
	// 	pq.pop();
	// }
	// mat C(n+1,n+1);
	// mat AA(n+1,1,1);
	// C.uni();
	// rep(i,n){
	// 	AA.d[i][1].x = w[i].S;
	// 	C.d[i][n].x = w[i].S;
	// }
	// C.d[n][n].x = 0;
	// AA=C.power(B/BB)*AA;
	// B%=BB;
	// typedef pair<ull,pair<int,int>> PP;
	// priority_queue<PP,vector<PP>,greater<PP>> pq1;
	// rep(i,n){
	// 	pq1.push(mkp(w[i].F,mkp(0,i)));
	// }
	// while(B){
	// 	B--;
	// 	PP top = pq1.top();
	// 	pq1.pop();
	// 	// cout<<top.F<<" "<<top.S<<endl;
	// 	top.F*=A;
	// 	top.S.F++;
	// 	pq1.push(top);
	// }
	// rep(i,n){
	// 	PP top = pq1.top();
	// 	pq1.pop();
	// 	cout<<top.F%MOD*powmod(A,AA.d[top.S.S][1].x+2+top.S.F)%MOD<<endl;
	// }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}