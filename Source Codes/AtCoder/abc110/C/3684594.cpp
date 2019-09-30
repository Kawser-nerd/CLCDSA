#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define dump(x)  cerr << #x << " = " << (x) << endl;

int main() {
  string S, T;
  int n;
  cin >> S;
  cin >> T;
  n = S.size();

  vector<int> r(26), r_inv(26);
  REP(i, r.size()) {
    r[i] = i;
    r_inv[i] = i;
  }

  REP(i, n) {
    char c1 = S[i], c2 = T[i];
    if (r[c1-'a'] == c2-'a') continue;
    
    int val1 = r[c1-'a'];
    r[c1-'a'] = c2-'a';

    int val2 = r_inv[c2-'a'];
    r[val2] = val1;

    r_inv[c2-'a'] = c1-'a';
    r_inv[val1] = val2;
  }
  REP(i, n) {
    char c1 = S[i], c2 = T[i];
    if (r[c1-'a'] != c2-'a') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}