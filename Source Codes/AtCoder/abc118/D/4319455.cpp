#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
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
#include <utility>
#include <vector>

#define FOR(i,k,n) for(int(i)=(k);(i)<(n);++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v),end(v)
#define debug(x) std::cerr<<#x<<": "<<x<<"\n"
#define debug2(x,y) std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<"\n"
#define debug3(x,y,z) std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<", "<<#z<<": "<<z<<"\n"

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

void print_(vi & ans) {
  for (int i = 9; i > 0; --i) {
    assert(ans[i] >= 0);
    rep (j, ans[i]) {
      printf("%d", i);
    }
  }
  printf("\n");
  exit(0);
}

int main() {
  int n, m;
  scan(n, m);
  vi use = {99999, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  map<int, int> canmake;
  rep (i, m) {
    int a;
    scan(a);
    canmake[use[a]] = max(canmake[use[a]], a);
  }
  vi cost(10, -1);
  for (auto&& p : canmake) {
    cost[p.first] = p.second;
  }
  //debug(cost);
  vi dp(n+1, -1);
  dp[0] = 0;
  FOR (i, 1, n+1) {
    FOR (j, 2, 8) {
      if (cost[j] < 0) { continue; }
      if (i - j < 0) { continue; }
      if (dp[i-j] < 0) { continue; }
      dp[i] = max(dp[i], dp[i-j] + 1);
    }
  }
  //debug(dp);

  vvi priuse_aux;
  FOR (i, 2, 8) {
    if (cost[i] < 0) { continue; }
    priuse_aux.push_back({cost[i], i});
  }
  sort(rbegin(priuse_aux), rend(priuse_aux));
  vi priuse(priuse_aux.size());
  rep (i, (int)priuse_aux.size()) {
    priuse[i] = priuse_aux[i][1];
  }
  //debug(priuse);

  vi ans(10, 0);
  for (int i = n; i > 0; ) {
    int next_i = i;
    rep (j, (int)priuse.size()) {
      int c = priuse[j];
      if (i - c < 0) { continue; }
      if (dp[i] - 1 == dp[i - c]) {
        ans[cost[c]] += 1;
        next_i = i - c;
        break;
      }
    }
    assert(next_i != i);
    i = next_i;
  }

  print_(ans);

  return 0;
}