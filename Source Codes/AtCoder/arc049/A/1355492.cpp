#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

//using
using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using PII = pair<int, int>;
using LL = long long;

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n)  for(int i=0;i<(n);i++)

//constant
const int INF = 1 << 29;
const double EPS = 1e-10;
const double PI = acos(-1.0);

//debug
#define dump(x)  cout << #x << " = " << (x) << endl;

int main() {
  string S;
  cin >> S;
  queue<int> num;
  REP(i, 4) {
    int tmp;
    cin >> tmp;
    num.push(tmp);
  }
  string ans = "";
  if(num.front() == 0) {
    ans += '"';
    num.pop();
  }
  int index = num.front();
  REP(i, S.size()+1) {
    if(i == index) {
      ans += '"';
      num.pop();
      index = num.empty() ? INF : num.front();
    }
    if(i<S.size()) ans += S[i];
  }
  cout << ans << endl;
  return 0;
}