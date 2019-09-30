#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
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
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) std::cerr<< #x <<": "<<x<<"\n"
#define debug2(x,y) std::cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<"\n"
 
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::vector<int> vi;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<ll> vll;
typedef std::vector<std::vector<ll> > vvll;
typedef std::deque<bool> db;
template<class T> using vv=std::vector<std::vector< T > >;

// cout vector
template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
  int len=v.size();s<<"\n";rep(i,len){s<<v[i];if(i<len-1){s << "\t";}}s<<"\n";return s; }
// cout 2-dimentional vector
template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<std::vector<T> >& vv) {
  int len=vv.size();rep(i,len){s<<vv[i];} return s; }
// cout deque
template<typename T> std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {
  int len=v.size();s<<"\n";rep(i,len){s<<v[i];if(i<len-1){s << "\t";}}s<<"\n";return s; }
// cout 2-dimentional deque
template<typename T> std::ostream& operator<<(std::ostream& s, const std::deque<std::deque<T> >& vv) {
  int len=vv.size();rep(i,len){s<<vv[i];} return s; }
// cout set<cout-able>
template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& v) {
  s<<"\n";for(auto elm : v){s<<elm<<"\t";}s<<"\n";return s; }

inline void scan(int&a){scanf("%d",&a);}
inline void scan(int&a,int&b){scanf("%d%d",&a,&b);}
inline void scan(int&a,int&b,int&c){scanf("%d%d%d",&a,&b,&c);}
inline void scan(int&a,int&b,int&c,int&d){scanf("%d%d%d%d",&a,&b,&c,&d);}
inline void scan(std::vector<int>&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(std::vector<std::vector<int> >&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(ll&a){scanf("%lld",&a);}
inline void scan(ll&a,ll&b){scanf("%lld%lld",&a,&b);}
inline void scan(ll&a,ll&b,ll&c){scanf("%lld%lld%lld",&a,&b,&c);}
inline void scan(ll&a,ll&b,ll&c,ll&d){scanf("%lld%lld%lld%lld",&a,&b,&c,&d);}
inline void scan(std::vector<ll>&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(std::vector<std::vector<ll> >&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(char&a){scanf(" %c",&a);}
inline void scan(std::vector<char>&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(std::vector<std::vector<char> >&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(std::string&s){char BUF[3000000];scanf(" %s",BUF);s=std::string(BUF);}

inline void print(int a){printf("%d\n",a);}
inline void print(int a,int b){printf("%d %d\n",a,b);}
inline void print(ll a){printf("%lld\n",a);}
inline void print(ll a,ll b){printf("%lld %lld\n",a,b);}
inline void print(std::string s){std::cout << s << "\n";}
inline void print_yn(bool flg){if(flg){printf("Yes\n");}else{printf("No\n");}}

using namespace std;

int main() {
  string s;
  scan(s);
  int x, y;
  scan(x, y);
  vi arms;
  int cnt = 0;
  int sz = s.length();
  if (s[sz-1] == 'F') {
    s += 'T';
    sz += 1;
  }
  for (char c : s) {
    if (c == 'F') {
      cnt += 1;
    } else {
      arms.push_back(cnt);
      cnt = 0;
    }
  }
  x -= arms[0];
  vi xy = {abs(x), abs(y)};
  vvi arm(2);
  sz = arms.size();
  FOR (i, 1, sz) {
    if (arms[i] == 0) { continue; }
    arm[i%2].push_back(arms[i]);
  }
  rep (i, 2) {
    int sum = 0;
    sz = arm[i].size();
    rep (j, sz) {
      sum += arm[i][j];
    }
    if (xy[i] < -sum || sum < xy[i] || (sum - xy[i]) % 2 == 1) {
      print_yn(false);
      return 0;
    }
    int aim = (sum - xy[i]) / 2;
    //debug(sum);
    //debug2(sz, aim);
    vv<bool> dp(sz+1, vector<bool>(aim+1, false));
    dp[0][0] = true;
    rep (j, sz) {
      rep (k, aim+1) {
        if (dp[j][k]) {
          dp[j+1][k] = true;
          if (k + arm[i][j] <= aim) {
            dp[j+1][k + arm[i][j]] = true; 
          }
        }
      }
    }
    if (!dp[sz][aim]) {
      print_yn(false);
      return 0;
    }
  }
  print_yn(true);

  return 0;
}