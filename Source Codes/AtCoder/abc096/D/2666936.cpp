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
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
 
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
  int len = v.size(); s << "\n";
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  s << "\n"; return s;
}

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
  int n;
  cin >> n;

  auto pr = Prime(55555);
  for (int p : pr.primes) {
    if (p % 5 == 2) {
      printf("%d ", p);
      n -= 1;
    }
    if (n == 0) {
      printf("\n");
      return 0;
    }
  }

  vi cnt(5, 0);
  for (int p : pr.primes) {
    cnt[p % 5] += 1;
  }
  debug(cnt);
  
  return 0;
}