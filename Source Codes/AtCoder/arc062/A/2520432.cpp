// include
//------------------------------------------
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// conversion
//------------------------------------------
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T> inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

// math
//-------------------------------------------
template <class T> inline T sqr(T x) { return x * x; }

// typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

// container util
//------------------------------------------
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i, c)                                                             \
  for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())

// repetition
//------------------------------------------
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

// constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);

// clear memory
#define CLR(a) memset((a), 0, sizeof(a))

// debug
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x)                                                               \
  cerr << #x << " = " << (x) << " (L" << __LINE__ << ")"                       \
       << " " << __FILE__ << endl;

int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  pair<LL, LL> ans;
  ans.first = a[0];
  ans.second = b[0];

  for (int i = 1; i < n; i++) {
    pair<LL, LL> tmp;
    tmp.first = (ans.first + a[i] - 1) / a[i];
    tmp.second = (ans.second + b[i] - 1) / b[i];
    if (tmp.first > tmp.second) {
      ans.first = a[i] * tmp.first;
      ans.second = b[i] * tmp.first;
    } else {
      ans.first = a[i] * tmp.second;
      ans.second = b[i] * tmp.second;
      dump(tmp.first);
      dump(tmp.second);
      dump(ans.first);
      dump(ans.second);
    }
  }
  cout << ans.first + ans.second;
  return 0;
}