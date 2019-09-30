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
using Vint = vector<int>;
using Vlli = vector<lli>;
using Wint = vector<Vint>;
using Wlli = vector<Vlli>;
using pii = pair<int, int>;
using pll = pair<lli, lli>;

constexpr int MOD = 1e9 + 7;
constexpr int INFi = 2e9 + 1;
constexpr lli INFl = (lli)(9e18) + 1;
const vector<pii> DXDY = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
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



constexpr int MAX_SIZE = 201;
int L[MAX_SIZE], n, dn;

int main(void){
  scanf("%d\n", &n);
  dn = 2 * n;
  REP(i, dn) scanf("%d", L + i);
  sort(L, L + dn);
  int ans = 0;
  for(int i = 0; i < dn; i += 2) ans += i[L];
  printf("%d\n", ans);
  return 0;
}