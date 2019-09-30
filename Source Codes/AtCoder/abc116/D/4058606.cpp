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
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define FOR(i,k,n) for(int(i)=(k);(i)<(n);++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v),end(v)
#define debug(x) //std::cerr<<#x<<": "<<x<<"\n"
#define debug2(x,y) //std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<"\n"
#define debug3(x,y,z) //std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<", "<<#z<<": "<<z<<"\n"

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
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

int main() {
  int n, k;
  scan(n, k);
  vvi ois(n);
  typedef pair<int, int> pii;
  vector<pii> dt(n);
  rep (i, n) {
    int t, d;
    scan(t, d);
    t -= 1;
    ois[t].push_back(d);
    pii tmp = {d, t};
    dt[i] = tmp;
  }
  rep (i, n) {
    sort(all(ois[i]));
    reverse(all(ois[i]));
  }
  sort(all(dt));
  reverse(all(dt));
  set<int> used_shurui;
  ll sum = 0;
  rep (i, k) {
    sum += dt[i].first;
    used_shurui.insert(dt[i].second);
  }
  vector<pii> willerase;
  rep (i, k) {
    int is = dt[i].second;
    int id = ois[is][0];
    if (used_shurui.find(is) != end(used_shurui) && dt[i] != (pii){id, is}) {
      willerase.push_back(dt[i]);
    }
  }
  sort(all(willerase));
  for (auto&& elm : willerase) {
    debug2(elm.first, elm.second);
  }

  vi willadd;
  rep (i, n) {
    if (ois[i].size() == 0) { continue; }
    if (used_shurui.find(i) != end(used_shurui)) { continue; }
    willadd.push_back(ois[i][0]);
  }
  sort(all(willadd));
  reverse(all(willadd));
  ll currentsize = used_shurui.size();
  int m1 = willadd.size();
  int m2 = willerase.size();
  int m = min(m1, m2);
  ll ans = sum + currentsize*currentsize;
  debug(ans);
  rep (i, m) {
    debug(sum);
    sum -= willerase[i].first;
    sum += willadd[i];
    debug(sum);
    currentsize += 1;
    ll cans = sum + currentsize*currentsize;
    debug3(willerase[i].first, willadd[i], currentsize);
    ans = max(ans, cans);
  debug(ans);
  }
  print(ans);

  return 0;
}