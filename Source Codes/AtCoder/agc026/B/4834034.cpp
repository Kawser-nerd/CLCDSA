#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>
#include <math.h>
using namespace std;

using lli = long long int;
using Vint = std::vector<int>;
using Vlli = std::vector<lli>;
using Wint = std::vector<Vint>;
using Wlli = std::vector<Vlli>;
using Vbool = std::vector<bool>;
using pii = std::pair<int, int>;
using pll = std::pair<lli, lli>;

constexpr int MOD = 1e9 + 7;
constexpr int INFi = 2e9 + 1;
constexpr lli INFl = (lli)(9e18) + 1;
const vector<pii> DXDY = {std::make_pair(1, 0), std::make_pair(-1, 0), std::make_pair(0, 1), std::make_pair(0, -1)};
constexpr char BR = '\n';

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define FOReq(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define rFOR(i, a, b) for(int (i) = (b); (i) >= (a); i--)
#define FORstep(i, a, b, step) for(int (i) = (a); i < (b); i += (step))
#define REP(i, n) FOR(i, 0, n)
#define rREP(i, n) rFOR(i, 0, (n-1))
#define vREP(ele, vec) for(auto &(ele) : (vec))
#define vREPcopy(ele, vec) for(auto (ele) : (vec))
#define SORT(A) std::sort((A).begin(), (A).end())



template <class T> inline int argmin(vector<T> vec){return min_element(vec.begin(), vec.end()) - vec.begin();}
template <class T> inline int argmax(vector<T> vec){return max_element(vec.begin(), vec.end()) - vec.begin();}
template <class T> inline void chmax(T &a, T b){a = max(a, b);}
template <class T> inline void chmin(T &a, T b){a = min(a, b);}
inline int toInt(string &s){int res = 0; for(char a : s) res = 10 * res + (a - '0'); return res;}
inline int toInt(const string s){int res = 0; for(char a : s) res = 10 * res + (a - '0'); return res;}
inline long long int toLong(string &s){lli res = 0; for(char a : s) res = 10 * res + (a - '0'); return res;}
inline long long int toLong(const string s){lli res = 0; for(char a : s) res = 10 * res + (a - '0'); return res;}
template <class T> inline std::string toString(T n){
  if(n == 0) return "0";
  std::string res = "";
  if(n < 0){n = -n;while(n != 0){res += (char)(n % 10 + '0'); n /= 10;}
  std::reverse(res.begin(), res.end()); return '-' + res;}
  while(n != 0){res += (char)(n % 10 + '0'); n /= 10;} std::reverse(res.begin(), res.end()); return res;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template<class T>
T gcd(T a, T b){
  if(b == 0) return a;
  T q = a % b;
  if(q == 0) return b;
  return gcd(b, q);
}

bool solve(lli a, lli b, lli c, lli d){
  // ????????
  if(a < b) return false;
  // ?? a >= b???????
  if(d < b) return false; // ???????????
  // ?? b <= d???????
  /*************************************/
  // c???? => d???
  // " ???? "q = d % b? ??????? (??, b?> c???)
  const lli q = d % b;
  if(c >= b) return true; // ?????????
  // a , d >= b and b > c???
  // Q, ???????????????
  //    --> c < f(x) < b??????????? !!!
  // then, find max a % b + kq mod b ~ (a + kq) (mod b)
  //  a + kq = mb + u, kq - mb = u - a; => gcd(q, b)???!!
  // ?) maximazing u - a = k * GCD => u = a + k * GCD
  a %= b;
  const lli GCD = gcd(b, q);
  lli U = ((b - a - 1 + b) % b) / GCD;
  lli MAX = a + U * GCD;
  //printf("a = %lld, GCD = %lld, MAX = %lld\n", a, GCD, Thinking_Number);
  return MAX <= c;
}

int main(void){
  int T; scanf("%d", &T);
  lli a, b, c, d;
  REP(_, T){
    scanf("\n%lld %lld %lld %lld", &a, &b, &c, &d);
    puts(solve(a, b, c, d) ? "Yes" : "No");
  }
  return 0;
}