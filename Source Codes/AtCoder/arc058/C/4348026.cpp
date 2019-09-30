#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define FOR(i,k,n) for(int(i)=(k);(i)<(n);++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v),end(v)
#define debug(x) std::cerr<<#x<<": "<<x<<"\n"
#define debug2(x,y) std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<"\n"
#define debug3(x,y,z) std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<", "<<#z<<": "<<z<<"\n"

using ll=long long;
using vi=std::vector<int>;
using vvi=std::vector<vi>;
using vll=std::vector<ll>;
using vvll=std::vector<vll>;
template<typename T> using vvec=std::vector<std::vector<T>>;
template<typename T>
auto make_v(size_t sz){return std::vector<T>(sz);}
template<typename T,typename... Ts>
auto make_v(size_t sz,Ts...ts){return std::vector<decltype(make_v<T>(ts...))>(sz,make_v<T>(ts...));}
template<typename T>
void fill_v(T&var,const T&x){var=x;}
template<typename V,typename T>
void fill_v(V&v,const T&x){for(auto&& w:v){fill_v(w,x);}}

template<typename T> std::ostream& operator<<(std::ostream&s,const std::vector<T>&v){
  int sz=v.size();s<<"\n";rep(i,sz){s<<v[i];if(i<sz-1){s<<"\t";}}s<<"\n";return s;}
template<typename T> std::ostream& operator<<(std::ostream&s,const std::vector<std::vector<T>>&v){
  for(auto&& w:v){s<<w;}return s;}
template<typename T> std::ostream& operator<<(std::ostream&s,const std::deque<T>&v){
  int sz=v.size();s<<"\n";rep(i,sz){s<<v[i];if(i<sz-1){s<<"\t";}}s<<"\n";return s;}
template<typename T> std::ostream& operator<<(std::ostream&s,const std::deque<std::deque<T>>&v){
  for(auto&& w:v){s<<w;}return s;}
template<typename T> std::ostream& operator<<(std::ostream&s, const std::set<T>&v){
  s<<"\n";for(auto&& elm:v){s<<elm<<"\t";}s<<"\n";return s;}

inline void scan(int&a){scanf("%d",&a);}
inline void scan(ll&a){scanf("%lld",&a);}
inline void scan(char&a){scanf(" %c",&a);}
inline void scan(double&a){scanf("%lf",&a);}
template<typename T>
inline void scan(std::vector<T>&v){for(auto&& sv:v){scan(sv);}}
template<typename First,typename...Args>
inline void scan(First&f,Args&...args){scan(f);scan(args...);}
inline void scan(std::string&s){char BUF[3000000];scanf(" %s",BUF);s=std::string(BUF);}
inline void print(int a){printf("%d\n",a);}
inline void print(ll a){printf("%lld\n",a);}
inline void print(double a){printf("%.12f\n",a);}
inline void print(std::string s){std::cout<<s<<"\n";}

using namespace std;

int mod = 1000000007;

int lg2(int x) {
  int h = 0;
  while (x >> h) ++h;
  return (1 << (h-1));
}

bool is_wafu(vi& x, int m) {
  return ((m >> (x[2] - 1)) & 1)
      && ((m >> (x[2] + x[1] - 1)) & 1)
      && ((m >> (x[2] + x[1] + x[0] - 1)) & 1);
}

int main() {
  int n;
  scan(n);
  vi x(3);
  scan(x);
  int sumd = x[0] + x[1] + x[2];

  ll bitdpmax = (1LL << (sumd + 1));
  vector<bool> wafu(bitdpmax);
  rep (i, bitdpmax) {
    wafu[i] = is_wafu(x, i);
  }
  vvll dp(n+1, vll(bitdpmax, 0));
  dp[0][0] = 1;
  rep (i, n) {
    rep (j, bitdpmax) {
      if (dp[i][j] == 0) { continue; }
      if (wafu[j]) { continue; }
      FOR (k, 1, 11) {
        int nj = (j << k) + (1 << (k-1));
        nj &= (bitdpmax - 1);
        dp[i+1][nj] = (dp[i+1][nj] + dp[i][j]) % mod;
      }
    }
  }

  ll ans = 1;
  rep (i, n) {
    ans = ans * 10 % mod;
  }
  rep (j, bitdpmax) {
    if (wafu[j]) { continue; }
    ans = (ans + mod - dp[n][j]) % mod;
  }
  print(ans);

  /*
  vll po10(50, 1);
  rep (i, 49) {
    po10[i+1] = po10[i] * 10 % mod;
  }

  int ma = max(x[0], x[1]);
  ma = max(ma, x[2]);
  vvec<vll> dp(n+1, vvll(3, vll(ma, 0)));
  dp[0][0][0] = 1;
  ll ans = 0;
  rep (i, n) {
    //dp[i+1]
    rep (j, 3) {
      rep (k, ma) {
        if (k >= x[j]) { break; }
        rep (l, x[j] - k) {
          dp[i+1][j][k + l] = (dp[i+1][j][k + l] + dp[i][j][k]) % mod;
        }
        ll add = dp[i][j][k] * po10[n - i - 1] % mod;
        if (j == 2) {
          debug3(i, j, k);
          ans = (ans + add) % mod;
          debug2(add, ans);
        } else {
          dp[i+1][j+1][0] = (dp[i+1][j+1][0] + dp[i][j][k]) % mod;
        }
        FOR (l, x[j] - k + 1, 11) {
          dp[i+1][0][0] = (dp[i+1][0][0] + dp[i][j][k]) % mod;
        }
      }
    }
  }
  debug(dp);
  print(ans);
  */

  return 0;
}