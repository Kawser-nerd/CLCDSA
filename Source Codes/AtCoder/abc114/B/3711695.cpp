#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>

using namespace std;

typedef long long LL;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define dump(x)  cerr << #x << " = " << (x) << endl;

int main() {
  string S;
  cin >> S;
  int res = 1e9;

  for (int i=0; i<S.size()-2; ++i) {
    int val = stoi(S.substr(i, 3));
    if (res > abs(val-753)) res = abs(val-753);
  }
  cout << res << endl;

  return 0;
}