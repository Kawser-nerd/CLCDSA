#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) //std::cerr<< #x <<": "<<x<<"\n"
#define debug2(x,y) std::cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<"\n"
 
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::vector<int> vi;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<ll> vll;
typedef std::vector<std::vector<ll> > vvll;
typedef std::deque<bool> db;
template<class T> using vv=std::vector<std::vector< T > >;

// cout vector
template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
  int len=v.size();s<<"\n";rep(i,len){s<<v[i];if(i<len-1){s << "\t";}}s<<"\n";return s; }
// cout 2-dimentional vector
template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<std::vector<T> >& vv) {
  int len=vv.size();rep(i,len){s<<vv[i];} return s; }
// cout deque
template<typename T> std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {
  int len=v.size();s<<"\n";rep(i,len){s<<v[i];if(i<len-1){s << "\t";}}s<<"\n";return s; }
// cout 2-dimentional deque
template<typename T> std::ostream& operator<<(std::ostream& s, const std::deque<std::deque<T> >& vv) {
  int len=vv.size();rep(i,len){s<<vv[i];} return s; }
// cout set<cout-able>
template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& v) {
  s<<"\n";for(auto elm : v){s<<elm<<"\t";}s<<"\n";return s; }

inline void scan(int&a){scanf("%d",&a);}
inline void scan(int&a,int&b){scanf("%d%d",&a,&b);}
inline void scan(int&a,int&b,int&c){scanf("%d%d%d",&a,&b,&c);}
inline void scan(int&a,int&b,int&c,int&d){scanf("%d%d%d%d",&a,&b,&c,&d);}
inline void scan(std::vector<int>&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(std::vector<std::vector<int> >&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(ll&a){scanf("%lld",&a);}
inline void scan(ll&a,ll&b){scanf("%lld%lld",&a,&b);}
inline void scan(ll&a,ll&b,ll&c){scanf("%lld%lld%lld",&a,&b,&c);}
inline void scan(ll&a,ll&b,ll&c,ll&d){scanf("%lld%lld%lld%lld",&a,&b,&c,&d);}
inline void scan(std::vector<ll>&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(std::vector<std::vector<ll> >&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(char&a){scanf(" %c",&a);}
inline void scan(std::vector<char>&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(std::vector<std::vector<char> >&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(std::string&s){char BUF[3000000];scanf(" %s",BUF);s=std::string(BUF);}

inline void print(int a){printf("%d\n",a);}
inline void print(int a,int b){printf("%d %d\n",a,b);}
inline void print(ll a){printf("%lld\n",a);}
inline void print(ll a,ll b){printf("%lld %lld\n",a,b);}
inline void print(std::string s){std::cout << s << "\n";}
inline void print_yn(bool flg){if(flg){printf("Yes\n");}else{printf("No\n");}}

using namespace std;

int mod = 1e9 + 7;
ll po(ll k, ll x) {
  if (x == 0) {
    return 1;
  }
  if (x == 1) {
    return k % mod;
  }
  ll y = po(k, x/2);
  y = y * y % mod;
  if (x % 2 == 1) {
    y = y * k % mod;
  }
  return y;
}

ll combination(ll n, ll k) {
  k = min(k, n-k);
  if (k == 0) {
    return 1;
  }
  ll ret = 1;
  FOR (i, n-k+1, n+1) {
    ret = ret * i % mod;
  }
  ll denomi = 1; // denominator
  FOR (i, 1, k+1) {
    denomi = denomi * i % mod;
  }
  ret = ret * po(denomi, mod-2) % mod; // inverse
  return ret;
}

int main() {
  int n;
  scan(n);
  vll a(n);
  scan(a);
  vll accum(n+1, 0);
  rep (i, n) {
    accum[i+1] = accum[i] + a[i];
  }
  debug(a);
  debug(accum);
  vll fact(n+9, 0);
  vll invf(n+9, 0);
  fact[0] = 1;
  invf[0] = 1;
  rep (i, n+8) {
    fact[i+1] = fact[i] * (i+1) % mod;
    invf[i+1] = po(fact[i+1], mod-2);
  }
  debug(fact);
  debug(invf);
  vll accum_fact(n+9, 0);
  rep (i, n+8) {
    accum_fact[i+1] = (accum_fact[i] + fact[i]) % mod;
  }

  vll unit_e(n, 1);
  rep (i, n-1) {
    unit_e[i] = unit_e[i] * fact[i+1] % mod;
    unit_e[i] = unit_e[i] * fact[n] % mod;
    unit_e[i] = unit_e[i] * invf[i+2] % mod;
  }
  vll accum_unit_e(n, 0);
  rep (i, n-1) {
    accum_unit_e[i+1] = (accum_unit_e[i] + unit_e[i]) % mod;
  }

  vll cnt(n, fact[n]);
  rep (i, n) {
    ll add = (accum_unit_e[n-1] - accum_unit_e[i]) % mod;
    if (add < 0) {
      add += mod;
    }
    cnt[i] = (cnt[i] + add) % mod;
    int j = n-1 - i;
    cnt[j] = (cnt[j] + add) % mod;
  }

  vll unit(n, 2);
  rep (i, n-2) {
    unit[i] = unit[i] * fact[i+1] % mod;
    unit[i] = unit[i] * fact[n] % mod;
    unit[i] = unit[i] * invf[i+3] % mod;
  }
  debug(unit);
  vll accum_unit(n, 0);
  rep (i, n-2) {
    accum_unit[i+1] = (accum_unit[i] + unit[i]) % mod;
  }

  vll accum_unit_wmax(n, 0);
  rep (i, n) {
    int left = i;
    int right = n-2 - i;
    if (left > right) {
      break;
    }
    accum_unit_wmax[i+1] = (accum_unit_wmax[i] + accum_unit[right] - accum_unit[left]) % mod;
    if (accum_unit_wmax[i+1] < 0) {
      accum_unit_wmax[i+1] += mod;
    }
  }
  FOR (i, 1, n-1) {
    int ma = min(i, n-1 - i);
    cnt[i] = (cnt[i] + accum_unit_wmax[ma]) % mod;
  }

  ll ans = 0;
  rep (i, n) {
    ll add = a[i] * cnt[i] % mod;
    ans = (ans + add) % mod;
  }
  print(ans);

  return 0;
}