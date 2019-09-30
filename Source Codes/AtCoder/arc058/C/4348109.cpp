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

  ll bitdpmax = (1LL << sumd);
  vector<bool> wafu(bitdpmax << 1);
  rep (i, bitdpmax << 1) {
    wafu[i] = is_wafu(x, i);
  }
  vll dp(bitdpmax, 0);
  dp[0] = 1;
  vll dp_;
  rep (i, n) {
    dp_.assign(bitdpmax, 0);
    rep (j, bitdpmax) {
      if (dp[j] == 0) { continue; }
      if (wafu[j]) { continue; }
      FOR (k, 1, 11) {
        int nj = (j << k) + (1 << (k-1));
        nj &= ((bitdpmax << 1) - 1);
        if (wafu[nj]) { continue; }
        nj &= (bitdpmax - 1);
        dp_[nj] = (dp_[nj] + dp[j]) % mod;
      }
    }
    swap(dp, dp_);
  }

  ll ans = 1;
  rep (i, n) {
    ans = ans * 10 % mod;
  }
  rep (j, bitdpmax) {
    ans = (ans + mod - dp[j]) % mod;
  }
  print(ans);

  return 0;
}