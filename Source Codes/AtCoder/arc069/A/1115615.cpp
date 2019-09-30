#include <iostream>
#include <sstream>
#include <string>
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
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>
#include <climits>
 
using namespace std;
 
#define FOR(k,a,b) for(int k=(a); k < (b); k++)
#define FORE(k,a,b) for(int k=(a); k <= (b); k++)
#define REP(k,a) for(int k=0; k < (a); k++)
 
#define ALL(c) (c).begin(), (c).end()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define RANGE(lb, x, ub) ((lb) <= (x) && (x) < (ub))
 
#define dump(x) cerr << #x << ": " << (x) << endl;
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
 
const int INF = 1000000000;
const double EPS = 1e-10;
const double PI = acos(-1.0);
 
int main(void) {
    ll n, m;
    cin >> n >> m;

    ll pairs = min(n, m / 2);
    n -= pairs;
    m -= pairs * 2;

    dump(n);
    dump(m);
    dump(pairs);

    if (m > 0) {
        pairs += m / 4;
    }

    printf("%lld\n", pairs);

    return 0;
}