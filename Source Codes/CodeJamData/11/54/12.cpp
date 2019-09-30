//Authored by dolphinigle
//GCJ R3 2011
//Jun 11 2011

#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))
#define RESET(Z,Y) memset(Z,Y,sizeof(Z))

#define SZ(Z) ((int)Z.size())
#define ALL(W) W.begin(), W.end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-8

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;
typedef vector<ll> vll;

bool IsQuad(ll num) {
  ll akar = (ll)sqrt((db)num);
  if (akar * akar == num ||
      (akar-1) * (akar-1) == num ||
      (akar+1) * (akar+1) == num) return true;
  return false;
}

string solve(string& str, int pos, ll num) {
  // TODO
  if (SZ(str) <= pos) {
    if (IsQuad(num)) return str;
    return "";
  }
  FORN(i, 2) {
    if (str[pos] != '?' && str[pos] != ('0' + i)) continue;
    char prev = str[pos];
    str[pos] = ('0' + i);
    string ret = solve(str, pos+1, num + (1LL << pos) * (ll)i);
    str[pos] = prev;
    if (ret != "") return ret;
  }
  return "";
}

int main() {

  int ntc;
  cin >> ntc;
  FORN(itc, ntc) {
    printf("Case #%d: ", itc+1);
    string str;
    cin >> str;
    reverse(ALL(str));
    string ret = solve(str, 0, 0LL);
    reverse(ALL(ret));
    cout << ret << endl;
  }

  return 0;
}
