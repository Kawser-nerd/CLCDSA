#include <iostream>
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


class Solver{
  private:
    // ?????
    int n, x;
    bool isDone = false;
    Vint A;
    // DP[i][j] := ????? i ?????? j ????? (????????)?????
    Wint DP; // DP[i + 1][j] = min(DP[i][j], A_("j - i - 1"))
  public:
    Solver(int nn, int xx){n = nn; x = xx;}
    // ??????????
    void getData(void){
      A.resize(n);
      vREP(ele, A) cin >> ele;
    }
    // 0 ~ k ????????, DP[k + 1][0 ~ n-1]???
    inline void update_DP(int k){
      REP(i, n){
        int idx = (i - k - 1);
        if(idx < 0) idx += n; // ???????
        DP[k + 1][i] = std::min(DP[k][i], A[idx]);
      }
    }
    // ??????????? : k?????????????????
    // f(k) = kx
    lli f(int k){
      lli res = (lli)k * x; // ??????????
      vREP(ele, DP[k]) res += ele;
      return res;
    }
    lli calculate_min_cost(void){
      if(not isDone){
        DP.resize(n, Vint(n));
        REP(i, n) DP[0].at(i) = A.at(i);
        REP(i, n-1) update_DP(i);
        isDone = true;
      }
      lli res = INFl;
      REP(i, n) chmin<lli>(res, f(i));
      return res;
    }
};

int main(void){
  int n, x; cin >> n >> x;
  Solver Donald_Trump(n, x);
  Donald_Trump.getData();
  cout << Donald_Trump.calculate_min_cost() << BR;
  return 0;
}