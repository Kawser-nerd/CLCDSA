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
inline void scan(std::string&s){char BUF[3000000];scanf(" %s",BUF);s=std::string(BUF);}
template<typename T>
inline void scan(std::vector<T>&v){for(auto&& sv:v){scan(sv);}}
template<typename First,typename...Args>
inline void scan(First&f,Args&...args){scan(f);scan(args...);}
inline void print(int a){printf("%d\n",a);}
inline void print(ll a){printf("%lld\n",a);}
inline void print(double a){printf("%.12f\n",a);}
inline void print(std::string s){std::cout<<s<<"\n";}

using namespace std;
#include <regex>

int INF = INT_MAX / 2;
int main() {
  int h, w;
  scan(h, w);
  //auto c = make_v<char>(h, w);
  vvi ox(h);
  int exdig = 11;
  int flag_x = (1 << exdig);
  rep (i, h) {
    char tmp;
    rep (j, w) {
      scan(tmp);
      if (tmp == 'o') {
        ox[i].push_back(j);
      } else if (tmp == 'x') {
        ox[i].push_back(j + flag_x);
      }
    }
  }
  int x_win_min = INF;
  int o_win_min = INF;
  rep (i, h) {
    if (ox[i].empty()) { continue; }
    if (ox[i].front() & flag_x) {
      x_win_min = min(x_win_min, ox[i].front() & (flag_x - 1));
    }
    if ((ox[i].back() & flag_x) == 0) {
      o_win_min = min(o_win_min, w - ox[i].back() - 1);
    }
  }
  if (x_win_min < INF || o_win_min < INF) {
    if (x_win_min < INF && o_win_min < INF) {
      if (o_win_min <= x_win_min) {
        print("o");
      } else {
        print("x");
      }
    } else if (o_win_min < INF) {
      print("o");
    } else if (x_win_min < INF) {
      print("x");
    }
    return 0;
  }

  ll o_space = 0;
  ll x_space = 0;
  vvi battle_list;
  rep (i, h) {
    if (ox[i].empty()) { continue; }
    vi sepa(1, 0);
    FOR (j, 1, (int)ox[i].size()) {
      if ((ox[i][j-1] & flag_x) && ((ox[i][j] & flag_x) == 0)) {
        sepa.push_back(j);
      }
    }
    sepa.push_back((int)ox[i].size());
    rep (j, (int)sepa.size() - 1) {
      int j_begin = sepa[j], j_end = sepa[j+1];
      int o_all = INF, x_all = INF, middle_cnt = 0;
      FOR (k, j_begin+1, j_end) {
        if (ox[i][k] & flag_x) {
          o_all = k - j_begin;
          x_all = j_end - k;
          middle_cnt = (ox[i][k] & (flag_x - 1)) - ox[i][k-1] - 1;
          break;
        }
      }
      assert(o_all != INF);
      if (middle_cnt > 1) {
        battle_list.push_back({o_all, middle_cnt, x_all});
      }
      FOR (k, 1, o_all) {
        o_space += k * (ox[i][j_begin + k] - ox[i][j_begin + k - 1] - 1);
      }
      FOR (k, 1, x_all) {
        x_space += k * (ox[i][j_end-1 - k + 1] - ox[i][j_end-1 - k] - 1); // ??
      }
    }
  }
  debug(battle_list);

  sort(all(battle_list), [](auto x, auto y) {
      return x[0] + x[2] > y[0] + y[2];
      });
  int turn = 0;
  for (auto&& battle : battle_list) {
    assert(battle[0] > 0 && battle[1] > 1 && battle[2] > 0);
    battle[1] -= 1;
    if (turn == 1) {
      x_space += (battle[2] - 1);
      battle[1] -= 1;
      turn = 0;
    }
    o_space += (battle[0] - 1) * ((battle[1] + 1) / 2);
    x_space += (battle[2] - 1) * (battle[1] / 2);
    if (battle[1] % 2 == 1) {
      turn = 1;
    }
  }
  if (turn == 1) {
    if (x_space == 0) {
      print("o");
      return 0;
    }
    x_space -= 1;
  }
  assert(o_space >= 0 && x_space >= 0);
  if (o_space > x_space) {
    print("o");
  } else {
    print("x");
  }

  return 0;
}