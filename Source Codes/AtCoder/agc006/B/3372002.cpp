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

vi ans;
void print_ans() {
  if (ans.size() > 0) {
    printf("Yes\n");
    for (int e : ans) {
      printf("%d\n", e);
    }
  } else {
    printf("No\n");
  }
  exit(0);
}

int main() {
  int n, x;
  scan(n, x);
  if (n == 2) {
    if (x == 2) {
      ans = {1, 2, 3};
    }
    print_ans();
  }
  if (n == 3) {
    if (x == 3) {
      ans = {1, 2, 3, 4, 5};
    } else if (x == 2) {
      ans = {4, 1, 2, 3, 5};
    } else if (x == 4) {
      ans = {1, 5, 4, 3, 2};
    }
    print_ans();
  }
  if (2 <= x && x <= 2*n-2) {
    ans.assign(2*n-1, 0);
    set<int> si;
    rep (i, 2*n-1) {
      si.insert(i+1);
    }
    if (x == 2) {
      ans[n-3] = x+1;
      ans[n-2] = x-1;
      ans[n-1] = x;
      ans[n] = x+2;
      si.erase(x+1);
      si.erase(x-1);
      si.erase(x);
      si.erase(x+2);
    } else {
      ans[n-3] = x-1;
      ans[n-2] = x+1;
      ans[n-1] = x;
      ans[n] = x-2;
      si.erase(x-1);
      si.erase(x+1);
      si.erase(x);
      si.erase(x-2);
    }
    rep (i, 2*n-1) {
      if (ans[i] != 0) {
        continue;
      }
      ans[i] = *(si.begin());
      si.erase(si.begin());
    }
  }
  print_ans();

  return 0;
}