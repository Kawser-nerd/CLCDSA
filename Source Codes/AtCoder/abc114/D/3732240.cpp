#include <iostream>
#include <map>

using namespace std;

typedef long long LL;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define dump(x)  cerr << #x << " = " << (x) << endl;

map<int, int> get_primes(int num, map<int, int> init) {
  for (int i = 2; i*i <= num; ++i) {
    if (num % i == 0) {
      int count = 0;
      while (num % i == 0) {
        num /= i;
        count++;
      }
      init[i] += count;
    }
  }
  if (num > 1) init[num] += 1;
  return init;
}

int factorial(int n, int m) {
  if (n == m) return 1;
  return n * factorial(n-1, m);
}

int comb(int a, int b) {
  return factorial(a, a-b) / factorial(b, 1);
}


int main() {
  int N;
  cin >> N;

  map<int, int> primes;
  REP(i, N) {
    primes = get_primes(i+1, primes);
  }

  int over4 = 0, over2 = 0, over14 = 0, over24 = 0, over74 = 0;
  for (auto p:primes) {
    if (p.second >= 4) over4++;
    if (p.second >= 2) over2++;
    if (p.second >= 14) over14++;
    if (p.second >= 24) over24++;
    if (p.second >= 74) over74++;
  }

  int res = 0;
  if (over4 >= 2 && over2 >= 3)
    res += comb(over4, 2) * (over2-2);
  if (over14 >= 1 && over4 >= 2)
    res += over14 * (over4-1);
  if (over24 >= 1 && over2 >= 2)
    res += over24 * (over2-1);
  if (over74 >= 1)
    res += over74;

  cout << res << endl;

  return 0;
}