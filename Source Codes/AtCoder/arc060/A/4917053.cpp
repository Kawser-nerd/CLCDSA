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
// ???? (for vector) : ?????????????? ; SORT(A) => COORDINATE_COMPRESSION(A)
#define COORDINATE_COMPRESSION(A) (A).erase(unique((A).begin(),(A).end()),(A).end())



template <class T> inline int argmin(std::vector<T> vec){return min_element(vec.begin(), vec.end()) - vec.begin();}
template <class T> inline int argmax(std::vector<T> vec){return max_element(vec.begin(), vec.end()) - vec.begin();}
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



int main(void){
  int n, a; scanf("%d %d\n", &n, &a);
  Vint A(n); vREP(ele, A) scanf("%d", &ele);
  // DP[i][j][k] := i???????? j ????, ??? k ???????
  // 0 ? i ? n, 0 ? j ? i, 0 ? k ? ? A_j
  vector<Wlli> Data(n+1);
  int til_sum = 0;
  lli tmp;
  Data.at(0).resize(1, Vlli(1, 1));
  REP(i, n){
    Data.at(i + 1).resize(i + 2, Vlli(til_sum + A.at(i) + 1, 0));
    FOReq(j, 0, i) FOReq(k, 0, til_sum){
      if((tmp = Data.at(i).at(j).at(k)) != 0){
        Data.at(i + 1).at(j).at(k) += tmp;
        Data.at(i + 1).at(j + 1).at(k + A.at(i)) += tmp;
      }
    }
    til_sum += A.at(i);
  }
  lli ans = 0;
  //printf("sum = %d\n", til_sum);
  Wlli &End = Data.at(n);
  int i = 1;
  while(i <= n and a * i <= til_sum){
    //printf("%d : %lld\n", i, End.at(i).at(a*i));
    ans += End.at(i).at(a * i);
    i++;
  }
  printf("%lld\n", ans);
  return 0;
}