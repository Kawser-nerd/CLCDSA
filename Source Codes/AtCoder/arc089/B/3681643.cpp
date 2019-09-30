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

int calc(vvi & imos, int x0, int x1, int y0, int y1) {
  return imos[x1][y1] - imos[x1][y0] - imos[x0][y1] + imos[x0][y0];
}
int calc(vvi & imos, vi & xy) {
  return calc(imos, xy[0], xy[1], xy[2], xy[3]);
}
int calc(vvi & imos, vvi & xys) {
  int ret = 0;
  for (auto xy : xys) {
    ret += calc(imos, xy);
  }
  return ret;
}

int main() {
  int n, k;
  scan(n, k);
  vvi black(2*k, vi(k, 0));
  vvi white(2*k, vi(k, 0));
  rep (i, n) {
    int x, y;
    char c;
    scan(x, y);
    scan(c);

    y %= (2*k);
    if (y >= k) {
      y -= k;
      x += k;
    }
    x %= (2*k);
    if (c == 'B') {
      black[x][y] += 1;
    } else if (c == 'W') {
      white[x][y] += 1;
    }
  }
  vvi imosb(2*k+1, vi(k+1, 0));
  vvi imosw(2*k+1, vi(k+1, 0));
  rep (i, 2*k) {
    rep (j, k) {
      imosb[i+1][j+1] = black[i][j];
      imosw[i+1][j+1] = white[i][j];
    }
  }
  FOR (i, 1, 2*k+1) {
    rep (j, k) {
      imosb[i][j+1] = imosb[i][j] + imosb[i][j+1];
      imosw[i][j+1] = imosw[i][j] + imosw[i][j+1];
    }
  }
  FOR (j, 1, k+1) {
    rep (i, 2*k) {
      imosb[i+1][j] = imosb[i][j] + imosb[i+1][j];
      imosw[i+1][j] = imosw[i][j] + imosw[i+1][j];
    }
  }
  //debug(imosb);
  //debug(imosw);
  int ans = 0;
  vvi r0;
  vvi r1;
  rep (i, k) {
    rep (j, k) {
      if (i == 0 && j == 0) {
        r0 = {{0, k, 0, k}};
        r1 = {{k, 2*k, 0, k}};
      } else if (i == 0) {
        r0 = {{0, k, j, k},
              {k, 2*k, 0, j}};
        r1 = {{0, k, 0, j},
              {k, 2*k, j, k}};
      } else if (j == 0) {
        r0 = {{i, i+k, 0, k}};
        r1 = {{0, i, 0, k},
              {i+k, 2*k, 0, k}};
      } else {
        r0 = {{i, i+k, j, k},
              {i+k, 2*k, 0, j},
              {0, i, 0, j}};
        r1 = {{i, i+k, 0, j},
              {i+k, 2*k, j, k},
              {0, i, j, k}};
      }
      ans = max(ans, calc(imosb, r0) + calc(imosw, r1));
      ans = max(ans, calc(imosb, r1) + calc(imosw, r0));
    }
  }
  print(ans);

  return 0;
}