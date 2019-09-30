#include <iostream>
using namespace std;

int H,W,A,B;
long fact[220000];
long rfact[220000];
const long MOD = 1000000007;
long extgcd(long a,long b,long &x,long &y){
  long d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}

long mod_inverse(long a) {
  long x, y;
  extgcd(a, MOD, x, y);
  x %= MOD;
  if(x < 0) x += MOD;
  return x;
}
void init() {
  rfact[0] = fact[0] = 1;
  for(int i = 1; i < 220000; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    rfact[i] = mod_inverse(fact[i]);
  }
}

long comb(long N, long K) {
  if(K < 0) return 0;
  if(N - K < 0) return 0;
  return ((fact[N] * rfact[K]) % MOD * rfact[N - K]) % MOD;
}

int main() {
  init();
  cin >> H >> W >> A >> B;
  long res = comb(H + W - 2, H - 1);
  for(int i = 0; i < B; i++) {
    res -= (comb(i + (H - A - 1), i) * comb(A - 1 + (W - 1 - i), A - 1)) % MOD;
    if(res < 0) res += MOD;
  }
  cout << res << endl;
}