#include <iostream>
using namespace std;
/*
 * n < s : ?????
 * n = s : b = n + 1
 * n > s : b
 */

// n % b + n / b % b 
//
long f(long b, long n) {
  if(n < b) return n;
  return f(b, n / b) + n % b;
}
long n, s;
int main() {
  cin >> n >> s;
//  for(int i = 2; i <= n + 1; i++) {
//    cout << i << ":" << f(i, n) << endl;
//  }
  for(long i = 2; i * i <= n || (n < 1000 && i <= n + 1); i++) {
    if(f(i, n) == s) {
      cout << i << endl;
      return 0;
    }
  }

  if(n < 1000){
    cout << -1 << endl;
    return 0;
  }
  long ans = n + 200;
  if(n == s) {
    ans = n + 1;
  }
  for(long i = 1; i * i <= n; i++) {
    // n / b == i
    // n / (i + 1) < b <= n / i
    long tmp = f(n / i, n);
    if((s - tmp) % i) continue;
    long m = (s - tmp) / i;
    // n / i - m?????
    long t = n / i - m;
    if(t >= 2) {
      if(f(t, n) == s) {
        ans = min(ans, t);
      }
    }
  }
  if(ans == n + 200) ans = -1;
  cout << ans << endl;
  return 0;
}