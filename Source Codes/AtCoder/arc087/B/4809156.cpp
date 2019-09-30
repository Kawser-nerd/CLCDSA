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


std::queue<int> X, Y;
int x, y, sum_x = 0;
char a;
bool is_x = true, first_kiss = true;

int main(void){
  int f = 0;
  while((a = getchar()) != '\n'){
    switch(a){
      case 'F':
        f++; break;
      case 'T':
        if(first_kiss){
          X.push(f);
          first_kiss = false;
        }
        else if(f != 0){
          if(is_x) X.push(f); else Y.push(f);
        }
        is_x = not is_x; f = 0; break;
    }
  }
  // ???T?????
  if(f != 0){
    if(is_x) X.push(f); else Y.push(f);
  }
  scanf("%d %d", &x, &y);
  const int Qx_size = X.size(), Qy_size = Y.size();
  // ???? : ?????? 0
  if(Qx_size == 0 and Qy_size == 0){
    puts((x == 0 and y == 0)? "Yes" : "No");
    return 0;
  }
  std::vector<std::set<int>> possible_x(Qx_size), possible_y(Qy_size + 1);
  possible_x[0] = {X.front()}; X.pop();
  possible_y[0] = {0};
  REP(i, Qx_size-1){
    int u = X.front(); X.pop();
    vREP(ele, possible_x[i]){
      possible_x[i+1].insert(ele + u);
      possible_x[i+1].insert(ele - u);
    }
  }
  REP(i, Qy_size){
    int u = Y.front(); Y.pop();
    vREP(ele, possible_y[i]){
      possible_y[i+1].insert(ele + u);
      possible_y[i+1].insert(ele - u);
    }
  }
  /*
  cout << "X : ";
  vREP(ele, possible_x[Qx_size-1]) cout << ele << ' '; cout << BR;
  cout << "Y : ";
  vREP(ele, possible_y[Qy_size]) cout << ele << ' '; cout << BR;
  */
  bool flag1 = possible_x[Qx_size-1].count(x) == 1,
       flag2 = possible_y[Qy_size].count(y) == 1;
  puts((flag1 and flag2) ? "Yes" : "No");
  return 0;
}