#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAXP 1000000

bool isp[MAXP + 1];
vector<int> primes;

int main() {
  for(int i = 0; i <= MAXP; i++) isp[i] = true;
  for(int i = 2; i * i <= MAXP; i++) {
    if(!isp[i]) continue;
    for(int j = i * i; j <= MAXP; j += i) {
      isp[j] = false;
    }
  }
  for(int i = 2; i <= MAXP; i++) {
    if(isp[i]) {
      primes.push_back(i);
    }
  }

  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    long long X; cin >> X;
    int result = 0;
    if(X != 1) {
      result++;
      for(int i = 0; i < primes.size(); i++) {
        long long p = primes[i];
        for(long long x = p * p; x <= X; x *= p) {
          result++;
        }
      }
    }
    printf("Case #%d: %d\n", t, result);
  }
}
