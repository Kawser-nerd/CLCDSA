#include <iostream>
#include <map>

using namespace std;

typedef long long LL;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define dump(x)  cerr << #x << " = " << (x) << endl;

LL mod = 1e9 + 7;

// mod. m ?? a ??? a^{-1} ?????
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

LL fact(LL a) {
  if (a == 0) return 1;
  return a * fact(a-1) % mod;
}

LL pattern(LL num, LL div) {
  LL inv_1 = modinv(fact(num), mod);
  LL inv_2 = modinv(fact(div-1), mod);

  return fact(num+div-1) % mod * inv_1 % mod * inv_2 % mod;
}

map<int, int> get_primes(int num) {
  map<int, int> res;
  for (int i = 2; i*i <= num; ++i) {
    if (num % i == 0) {
      int count = 0;
      while (num % i == 0) {
        num /= i;
        count++;
      }
      res[i] = count;
    }
  }
  if (num > 1) res[num] = 1;
  return res;
}

int main() {
  int N, M;
  cin >> N >> M;

  auto primes = get_primes(M);
  LL res = 1;
  for (auto e : primes) {
    res = res * pattern(e.second, N) % mod;
  }

  cout << res << endl;

  return 0;
}