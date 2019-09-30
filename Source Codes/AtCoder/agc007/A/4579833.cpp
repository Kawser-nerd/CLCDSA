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
  if(n < 0){n = -n;while(n != 0){res += (char)(n % 10 + '0'); n /= 10;} std::reverse(res.begin(), res.end()); return '-' + res;}
  while(n != 0){res += (char)(n % 10 + '0'); n /= 10;} std::reverse(res.begin(), res.end()); return res;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


using Vbool = std::vector<bool>;
using Wbool = std::vector<Vbool>;

#define ISIN(i, j, h, w) (0 <= (i) and (i) < (h) and 0 <= (j) and (j) < (w))

bool judge(Wbool A, int h, int w){
  int i = 0, j = 0; A[i][j] = false;
  while(i != (h - 1) || j != (w - 1)){
    int cnt = 0, next_addx, next_addy;
    vREP(ele, DXDY){
      int x = i + ele.first, y = j + ele.second;
      if(ISIN(x, y, h, w)){
        if(A[x][y]){
          A[x][y] = false;
          cnt++;
          next_addx = ele.first;
          next_addy = ele.second;
        }
      }
    }
    if(cnt != 1) return false;
    if(next_addx != 1 and next_addy != 1) return false;
    i += next_addx;
    j += next_addy;
  }
  REP(ii, h) REP(jj, w) if(A[ii][jj]) return false;
  return true;
}


int main(void){
  int h, w; cin >> h >> w;
  Wbool data(h, Vbool(w));
  getchar();
  REP(i, h){
    REP(j, w) data[i][j] = (getchar() == '#');
    getchar(); // \n??????
  }
  cout << (judge(data, h, w) ? "Possible" : "Impossible" ) << BR;
  return 0;
}