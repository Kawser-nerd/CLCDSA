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
#define debug(x) //std::cerr<<#x<<": "<<x<<"\n"
#define debug2(x,y) //std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<"\n"
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

int m;
vi ans;
void print_() {
  rep (i, m) {
    printf("%d%c", ans[i], " \n"[i == m-1]);
  }
}
void yes() {
  printf("YES\n");
  print_();
  exit(0);
}
void no() {
  printf("NO\n");
  exit(0);
}

vi gray_code(int start, int end) {
  int sz = end - start;
  vi ret(sz);
  rep (i, sz) {
    int j = start + i;
    ret[i] = (j ^ (j >> 1));
  }
  return ret;
}

vi gray_code_symmetry(int n, int start, int end) {
  int sz = end - start;
  vi orig = gray_code(start, end);
  vi ret(sz, 0);
  rep (i, sz) {
    rep (j, n) {
      int i_orig = n-1 - j;
      ret[i] |= ((orig[i] >> i_orig) & 1) * (1 << j);
    }
  }
  return ret;
}

bool check_gray(vi& gc) {
  int sz = gc.size();
  rep (i, sz-1) {
    assert(__builtin_popcount(gc[i] ^ gc[i+1]) == 1);
  }
  return true;
}

vi gc1 = {0, 1};
vi gc2 = {0, 1, 3, 2};

vi step1_1(int diff) {
  assert(diff >= 3 && diff % 2 == 1);
  if (diff == 3) {
    return (vi){0, 1, 3, 2, 6, 4, 5, 7};
  }
  auto r2 = step1_1(diff - 2);
  vi ret(1 << diff);
  rep (i, (1 << (diff - 2))) {
    rep (j, 2) {
      int ind_gc1 = (j - i) % 2;
      if (ind_gc1 < 0) {
        ind_gc1 += 2;
      }
      ret[i * 2 + j] = r2[i] + (gc1[ind_gc1] << (diff - 2));
    }
  }
  auto later = gray_code(0, (1 << (diff - 1)));
  reverse(all(later));
  rep (i, (1 << (diff - 1))) {
    later[i] ^= ((1 << diff) - 1);
  }
  copy(all(later), begin(ret) + (1 << (diff - 1)));
  debug(ret);
  return ret;
}

vi step1_2(int dig, vi& base) {
  int sz = base.size();
  assert((1 << dig) == sz);
  vi ret(sz << 2);
  rep (i, sz) {
    rep (j, 4) {
      int ind_gc2 = (j - i) % 4;
      if (ind_gc2 < 0) {
        ind_gc2 += 4;
      }
      ret[i * 4 + j] = base[i] + (gc2[ind_gc2] << dig);
    }
  }
  return ret;
}

vi step1_3(int dig, vi& base) {
  int sz = base.size();
  assert((1 << dig) == sz);
  vi ret(sz << 1);
  rep (i, sz) {
    rep (j, 2) {
      int ind_gc1 = (j - i) % 2;
      if (ind_gc1 < 0) {
        ind_gc1 += 2;
      }
      ret[i * 2 + j] = base[i] + (gc1[ind_gc1] << dig);
    }
  }
  return ret;
}

vi step1(int n, int diff) {
  if (diff == 1) {
    return gray_code_symmetry(n, 0, (1 << n));
  }
  auto base = step1_1(diff);
  debug(base);
  rep (i, (n - diff) / 2) {
    base = step1_2(diff + i * 2, base);
  }
  if ((n - diff) % 2 == 1) {
    base = step1_3(n-1, base);
  }
  debug(base);
  check_gray(base);
  return base;
}

vi step2(int n, int a, int b, vi& s1) {
  int flip = 0;
  int msb = __builtin_popcount(a & b);
  int lsb = __builtin_popcount(a & (b ^ ((1 << n) - 1)));
  rep (i, msb) {
    flip |= (1 << (n-1 - i));
  }
  rep (i, lsb) {
    flip |= (1 << i);
  }
  debug(flip);
  vi s2(1 << n);
  assert(s1.size() == s2.size());
  rep (i, (1 << n)) {
    s2[i] = (s1[i] ^ flip);
  }
  debug(s2);
  check_gray(s2);
  return s2;
}

int step3_1(int x, vvi& swaps) {
  int sz = swaps[0].size();
  rep (i, sz) {
    int j = swaps[0][i];
    int k = swaps[1][i];
    int oj = ((x >> j) & 1);
    int ok = ((x >> k) & 1);
    if (oj == ok) { continue; }
    int mask = ((1 << j) + (1 << k));
    x ^= mask;
  }
  return x;
}

vi step3(int n, int a, int b, vi& s2) {
  vvi swaps(2);
  int s2_0 = s2[0];
  int s2_m = s2[(1 << n) - 1];
  int current;
  vi target(n);
  rep (i, n) {
    target[i] = ((a >> i) & 1) + ((b >> i) & 1) * 2;
  }
  rep (j, 4) {
    rep (i, n) {
      current = ((s2_0 >> i) & 1) + ((s2_m >> i) & 1) * 2;
      if (current == target[i]) { continue; }
      if (current == j) {
        swaps[0].push_back(i);
      }
      if (target[i] == j) {
        swaps[1].push_back(i);
      }
    }
    assert(swaps[0].size() == swaps[1].size());
    s2_0 = step3_1(s2[0], swaps);
    s2_m = step3_1(s2[(1 << n) - 1], swaps);
  }
  debug(swaps);

  vi s3(1 << n);
  rep (i, (1 << n)) {
    s3[i] = step3_1(s2[i], swaps);
  }
  return s3;
}

int main() {
  int n, a, b;
  scan(n, a, b);
  bool swapped = false;
  if (a > b) {
    swap(a, b);
    swapped = true;
  }
  m = (1 << n);
  int diff = __builtin_popcount(a ^ b);
  if (diff % 2 == 0) {
    no();
  }
  auto s1 = step1(n, diff);
  debug(s1);
  auto s2 = step2(n, a, b, s1);
  debug(s2);
  assert(__builtin_popcount(s2[0]) == __builtin_popcount(a));
  assert(__builtin_popcount(s2[m-1]) == __builtin_popcount(b));
  ans = step3(n, a, b, s2);
  if (swapped) {
    swap(a, b);
    reverse(all(ans));
  }
  yes();

  return 0;
}