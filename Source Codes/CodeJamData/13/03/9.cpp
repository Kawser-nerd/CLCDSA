#include <iostream>
#include <gmpxx.h> // libgmp, can be found in most linux distributions
#include <sstream>
#include <vector>
using namespace std;

bool isPalindrome(const mpz_class& v) {
  ostringstream oss;
  oss << v;
  string s = oss.str();
  for(int i = 0; i < s.size(); ++i) {
    if(s[s.size()-1-i] != s[i])
      return false;
  }
  return true;
}

char st[1000];
int n[1000];
int n2[1000];

vector<pair<mpz_class, mpz_class>> ranges;
vector<unsigned long long> ret;

void check(const mpz_class& v) {
    for(unsigned i = 0; i < ranges.size(); ++i) {
      if(v >= ranges[i].first && v <= ranges[i].second)
        ++ret[i];
    }
}

void calc_dfs(unsigned depth, unsigned len, unsigned totallen) {
  for(int i = 0; i < 2 * totallen; ++i)
    n2[i] = 0;
  for(int i =0 ; i < totallen; ++i)
    for(int j = 0; j < totallen; ++j)
      n2[i+j] += n[i] * n[j];
  for(int i = 0; i < 2 * totallen; ++i)
    if(n2[i] >= 10)
      return;
  if(len == depth) {
    st[totallen] = 0;
    mpz_class v((const char*)st);
    mpz_class v2 = v*v;
    check(v2);
    return;
  }
  for(int i = depth == 0 ? 1 : 0; i < 3; ++i) {
    st[depth] = '0' + i; n[depth] = i;
    st[totallen - 1 - depth] = '0' + i; n[totallen - 1 - depth] = i;
    calc_dfs(depth+1, len, totallen);
  }
  n[depth] = 0;
  n[totallen - 1 - depth] = 0;
}


void calcFairSquare() {
  int l = 50;
  for(int i = 2; i <= l; ++i) {
    calc_dfs(0, (i+1)/2, i);
  }
}
int main() {
  int T;
  cin >> T;
  ret.resize(T);
  ranges.resize(T);
  for(int i = 0; i < T; ++i) 
      cin >> ranges[i].first >> ranges[i].second;
  check(1);
  check(4);
  check(9);
  calcFairSquare();
  for(int i = 0; i < T; ++i) 
    cout << "Case #" << (i+1) <<": " << ret[i] << endl;
  return 0;
}
