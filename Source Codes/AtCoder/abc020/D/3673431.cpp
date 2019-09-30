#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef long long LL;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define dump(x)  cerr << #x << " = " << (x) << endl;

LL mod = 1e9 + 7;

vector<int> get_primes(int K) {
  vector<int> res;
  for(int i=2; i*i <= K; ++i) {
    if (K % i == 0) {
      res.push_back(i);
      while (K % i == 0) K /= i;
    }
  }
  if (K > 1) res.push_back(K);
  return res;
}


LL solve(LL K, LL N) {
  vector<int> primes = get_primes(K);
  int num = primes.size();

  LL res = 0;
  for (int msk=0; msk < 1<<num; ++msk) {
    LL mul = 1;
    REP(i, num) if ((msk>>i) & 1) mul *= primes[i];
    LL n = N / mul;
    LL val = (1+n)*n/2 %mod *mul%mod;
    res += val*(__builtin_popcount(msk)%2 ? -1+mod : 1) % mod;
  }
  return res % mod;
}

int main() {
  LL N, K;
  cin >> N >> K;

  LL result = 0;
  for(int i=1; i*i<=K; ++i) {
    if (K % i == 0) {
      result += K*solve(K/i, N/i);
      result %= mod;
      if (K/i != i) {
        result += K*solve(i, N*i/K);
        result %= mod;
      }
    }
  }

  cout << result << endl;

  return 0;
}