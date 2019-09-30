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

class Save_Me_If_I_Become_My_Demons{
  using data = tuple<int, int, int>;
  private:
    int n, first_positive_index;
    vector<data> Data;
  public:
    Save_Me_If_I_Become_My_Demons(int nn){
      n = nn; Data.resize(nn);
    }
    ~Save_Me_If_I_Become_My_Demons(void){};
    void getIn(void){
      int x, y, h;
      REP(i, n){
        cin >> x >> y >> h;
        Data.at(i) = make_tuple(h, x, y);
      }
    }
    void preprocessing(void){
      std::sort(Data.begin(), Data.end());
      int h;
      REP(i, n){
        h = std::get<0>(Data.at(i));
        if(h > 0){first_positive_index = i; return;}
      }
    }
    inline int compute_height_if_positive(int i, int j, int idx){
      int x, y, h;
      tie(h, x, y) = Data.at(idx);
      return h + abs(x - i) + abs(y - j);
    }
    int compute_height(int i, int j){
      int ans_maybe = compute_height_if_positive(i, j, first_positive_index);
      FOR(idx, first_positive_index + 1, n) if(compute_height_if_positive(i, j, idx) != ans_maybe) return 0;
      REP(idx, first_positive_index){
        int x, y;
        tie(std::ignore, x, y) = Data.at(idx);
        if(ans_maybe > abs(x - i) + abs(y - j)) return 0;
      }
      return ans_maybe;
    }
    std::tuple<int, int, int> calculate(void){
      FOReq(i, 0, 100) FOReq(j, 0, 100){
        int res = compute_height(i, j);
        if(res != 0)
        return std::forward_as_tuple(i, j, res);
      }
    }
};

int main(void){
  int n; scanf("%d", &n);
  Save_Me_If_I_Become_My_Demons GREAT(n);
  GREAT.getIn();
  GREAT.preprocessing();
  int Cx, Cy, H;
  std::tie(Cx, Cy, H) = GREAT.calculate();
  printf("%d %d %d\n", Cx, Cy, H);
  return 0;
} ./Main.cpp:101:5: warning: control may reach end of non-void function [-Wreturn-type]
    }
    ^
1 warning generated.