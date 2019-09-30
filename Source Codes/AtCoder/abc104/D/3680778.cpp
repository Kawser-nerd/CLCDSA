#include <iostream>
#include <string>
#define ll long long
using namespace std;

const int MOD = 1000000007;

int main() {
  string S;
  cin >> S;

  int len = S.size();
  ll a = 0, ab = 0, abc = 0, all_s = 1;

  for (int i = 0; i < len; i++) {
    if (S[i] == 'A')
      a = (a + all_s) % MOD;
    else if (S[i] == 'B')
      ab = (ab + a) % MOD;
    else if (S[i] == 'C')
      abc = (abc + ab) % MOD;
    else if (S[i] == '?') {
      abc   = (abc * 3 + ab) % MOD;
      ab    = (ab * 3 + a) % MOD;
      a     = (a * 3 + all_s) % MOD;
      all_s = (all_s * 3) % MOD;
    }
  }
  cout << abc << endl;
}