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

double calc_aux(int curv, int t, int limv) {
  if (curv + t <= limv) {
    return t;
  }
  if (curv > limv) {
    int rt = t - (curv - limv);
    return (double)rt / 2;
  } else {
    int rt = t - (limv - curv);
    return limv - curv + (double)rt / 2;
  }
}

pair<double, int> calc(int curv, int t, int maxv, int limv) {
  double peak_t = calc_aux(curv, t, limv);
  double peak_v = curv + peak_t;
  double t1, t2;
  if (peak_v <= maxv) {
    t1 = peak_t;
    t2 = peak_t;
  } else {
    t1 = maxv - curv;
    if (limv >= maxv) {
      t2 = t;
    } else {
      t2 = t - (maxv - limv);
    }
  }
  int endv = curv + t1 - (t - t2);
  double s = 0;
  s += (curv*2 + t1) * t1 / 2;
  s += (curv + t1) * (t2 - t1);
  s += (curv + t1 + endv) * (t - t2) / 2;

  return make_pair(s, endv);
}

int main() {
  int n;
  scan(n);
  vi t(n);
  scan(t);
  vi accum_t(n+1, 0);
  rep (i, n) {
    accum_t[i+1] = accum_t[i] + t[i];
  }
  vi vel(n);
  scan(vel);
  vel.push_back(0);
  int curv = 0;
  double sum = 0;
  rep (i, n) {
    int limv = INT_MAX;
    FOR (j, i+1, n+1) {
      limv = min(limv, vel[j] + accum_t[j] - accum_t[i+1]);
    }
    auto res = calc(curv, t[i], vel[i], limv);
    sum += res.first;
    curv = res.second;
  }
  printf("%.9f\n", sum);

  return 0;
}