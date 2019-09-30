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
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) std::cerr<< #x <<": "<<x<<"\n"
#define debug2(x,y) std::cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<"\n"
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<bool> db;
template<class T> using vv=vector<vector< T > >;

inline void scan(int&a){scanf("%d",&a);}
inline void scan(int&a,int&b){scanf("%d%d",&a,&b);}
inline void scan(int&a,int&b,int&c){scanf("%d%d%d",&a,&b,&c);}
inline void scan(int&a,int&b,int&c,int&d){scanf("%d%d%d%d",&a,&b,&c,&d);}
inline void scan(vector<int>&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(vector<vector<int> >&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(ll&a){scanf("%lld",&a);}
inline void scan(ll&a,ll&b){scanf("%lld%lld",&a,&b);}
inline void scan(ll&a,ll&b,ll&c){scanf("%lld%lld%lld",&a,&b,&c);}
inline void scan(ll&a,ll&b,ll&c,ll&d){scanf("%lld%lld%lld%lld",&a,&b,&c,&d);}
inline void scan(vector<ll>&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(vector<vector<ll> >&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(char&a){scanf(" %c",&a);}
inline void scan(vector<char>&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(vector<vector<char> >&v){int sz=v.size();rep(i,sz){scan(v[i]);}}
inline void scan(string&s){char BUF[3000000];scanf(" %s",BUF);s=string(BUF);}

inline void print(int a){printf("%d\n",a);}
inline void print(int a,int b){printf("%d %d\n",a,b);}
inline void print(ll a){printf("%lld\n",a);}
inline void print(ll a,ll b){printf("%lld %lld\n",a,b);}
inline void print(string s){cout << s << "\n";}
inline void print_yn(bool flg){if(flg){printf("Yes\n");}else{printf("No\n");}}

// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len=v.size();s<<"\n";rep(i,len){s<<v[i];if(i<len-1){s << "\t";}}s<<"\n";return s; }
// cout 2-dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len=vv.size();rep(i,len){s<<vv[i];} return s; }
// cout deque
template<typename T> ostream& operator<<(ostream& s, const deque<T>& v) {
  int len=v.size();s<<"\n";rep(i,len){s<<v[i];if(i<len-1){s << "\t";}}s<<"\n";return s; }
// cout 2-dimentional deque
template<typename T> ostream& operator<<(ostream& s, const deque< deque<T> >& vv) {
  int len=vv.size();rep(i,len){s<<vv[i];} return s; }
// cout set<cout-able>
template<typename T> ostream& operator<<(ostream& s, const set<T>& v) {
  s<<"\n";for(auto elm : v){s<<elm<<"\t";}s<<"\n";return s; }

int main() {
  int n;
  ll X;
  scan(n); scan(X);
  vll x(n);
  scan(x);
  vll accum(n+1, 0LL);
  rep (i, n) {
    accum[i+1] = accum[i] + x[i];
  }

  vector<mp::cpp_int> keisu(n, 0);
  keisu[0] = 5;
  FOR (i, 1, n) {
    keisu[i] = (i + 1) * 2 + 1;
  }

  mp::cpp_int mineng = LLONG_MAX; // can be proved
  FOR (k, 1, n+1) {
    mp::cpp_int eng = X * k;
    int ind = n;
    rep (i, n) {
      if (ind - k >= 0) {
        eng += keisu[i] * (accum[ind] - accum[ind-k]);
        ind -= k;
      } else {
        eng += keisu[i] * (accum[ind] - accum[0]);
        break;
      }
    }
    mineng = min(mineng, eng);
  }
  cout << mineng + X * n << "\n";
  //print(mineng + X * n);

  return 0;
}