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

struct Prime {
  int max_check;
  int max_prime;
  int prime_number;
  vector<int> primes;
  map<int, int> prime_id;
  Prime() {};
  Prime(int m) {
    initialize(m);
  };
  void initialize(int m) {
    sieve(m);
    prime_number = (int)primes.size();
    max_check = m;
  }

  void sieve(int m) {
    max_prime = 2;
    deque<bool> is_prime(m+1, true);
    is_prime[0] = is_prime[1] = false;
    int i;
    for (i = 2; i <= m; ++i) {
      if (!is_prime[i]) {
        continue;
      }
      if (i * i > m) {
        break;
      }
      for (int j = i*2; j <= m; j += i) {
        is_prime[j] = false;
      }
      prime_id[i] = (int)primes.size();
      primes.push_back(i);
      max_prime = i;
    }
    for (int j = i; j <= m; ++j) {
      if (!is_prime[j]) {
        continue;
      }
      prime_id[j] = (int)primes.size();
      primes.push_back(j);
      max_prime = j;
    }
  }

  map<int, int> prime_factor(ll x) {
    map<int, int> ret;
    if ((ll)max_check * (ll)max_check < x) {
      return ret;
    }
    for (int i = 0; i < prime_number; ++i) {
      if (x == 1) {
        break;
      }
      while (x % primes[i] == 0) {
        x /= primes[i];
        ret[primes[i]] += 1;
      }
    }
    if (x != 1) {
      ret[x] += 1;
    }
    return ret;
  }
};

int main() {
  int n = 100000;
  auto pr = Prime(n);
  vi ln(n, 0);
  rep (i, n) {
    if (i % 2 == 0) {
      continue;
    }
    int j = (i + 1) / 2;
    if (pr.prime_id.find(i) != pr.prime_id.end() && pr.prime_id.find(j) != pr.prime_id.end()) {
      ln[i] = 1;
    }
  }
  vi accum(n+1, 0);
  rep (i, n) {
    accum[i+1] = accum[i] + ln[i];
  }
  int q;
  scan(q);
  rep (i, q) {
    int l, r;
    scan(l, r);
    int ans = accum[r+1] - accum[l];
    print(ans);
  }

  return 0;
}