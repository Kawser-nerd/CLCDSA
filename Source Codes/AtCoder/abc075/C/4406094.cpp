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

vvi edge;
vi prenum;
vi lowest;
vi parent;
int timer;

void dfs(int u, int prev) {
  prenum[u] = timer;
  lowest[u] = timer;
  timer += 1;

  for (auto v : edge[u]) {
    if (prenum[v] < 0) {
      parent[v] = u;
      dfs(v, u);
      lowest[u] = min(lowest[u], lowest[v]);
    } else if (v != prev) {
      lowest[u] = min(lowest[u], prenum[v]);
    }
  }
}

int main() {
  int n, m;
  scan(n, m);
  edge.resize(n);
  prenum.resize(n, -1);
  lowest.resize(n);
  parent.resize(n);
  rep (i, m) {
    int a, b;
    scan(a, b);
    a -= 1; b -= 1;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  timer = 0;
  dfs(0, -1);

  set<vi> ans;
  FOR(i, 1, n) {
    if (prenum[parent[i]] < lowest[i]) {
      int mi = min(parent[i], i);
      int ma = max(parent[i], i);
      ans.insert({mi, ma});
    }
  }
  print((int)ans.size());
  return 0;
}