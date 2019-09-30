#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

using lli = long long int;
using Vint = vector<int>;
using Vlli = vector<lli>;
using Wint = vector<Vint>;
using Wlli = vector<Vlli>;
using pii = pair<int, int>;
using pll = pair<lli, lli>;

const int MOD = 1e9 + 7;
const int INFi = 2e9 + 1;
const lli INFl = (lli)(9e18) + 1;
const vector<pii> DXDY = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
const char BR = '\n';

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define FOReq(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define rFOR(i, a, b) for(int (i) = (b); (i) >= (a); i--)
#define FORstep(i, a, b, step) for(int (i) = (a); i < (b); i += (step))
#define REP(i, n) FOR(i, 0, n)
#define rREP(i, n) rFOR(i, 0, (n-1))
#define vREP(ele, vec) for(auto &(ele) : (vec))
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
  if(n < 0){n = -n;while(n != 0){res += (char)(n % 10 + '0'); n /= 10;} std::reverse(res.begin(), res.end()); return '-' + res;}
  while(n != 0){res += (char)(n % 10 + '0'); n /= 10;} std::reverse(res.begin(), res.end()); return res;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void gone_shoot(int n, int x){
  std::queue<int> timpo;
  int t1, t2, t3, t4;
  // 1, 2, ..., n - 1, n , n + 1, ..., 2n - 1
  if(x == 2) t1 = x + 1, t2 = x, t3 = x - 1, t4 = x + 2;
  else t1 = x - 1, t2 = x, t3 = x + 1, t4 = x - 2;
  FOReq(i, 1, 2 * n - 1) if(i != t1 and i != t2 and i != t3 and i != t4) timpo.push(i);
  REP(i, n - 2){printf("%d\n", timpo.front()); timpo.pop();}
  printf("%d\n%d\n%d\n%d\n", t1, t2, t3, t4);
  REP(i, n - 3) {printf("%d\n", timpo.front()); timpo.pop();}
}


int main(void){
  int n, x; scanf("%d%d", &n, &x);
  if(x == 1 || x == 2 * n - 1) puts("No");
  else if(n == 2) puts("Yes\n1\n2\n3");
  else {puts("Yes"); gone_shoot(n, x);}
  return 0;
}