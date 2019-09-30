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
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SZ(x) (int)(x).size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const char dir[] = "NSEW";

void alg() {
    int x, y;
    cin >> x >> y;
    bool chx = (x < 0);
    bool chy = (y < 0);
    x = abs(x);
    y = abs(y);
    int sum = 0;
    int r = 0;
    while (sum < x + y || (sum - x - y) % 2 == 1) {
        ++r;
        sum += r;
    }
    vector<int> v;
    for (int i = 1; i <= r; ++i) {
        v.PB(i);
    }
    string s(r + 1, ' ');
    for (int i = r; i >= 1; --i) {
        if (abs(x - i) + abs(y) < abs(x) + abs(y - i)) {
            s[i] = dir[2 ^ chx];
            if (x < i) {
                chx ^= 1;
            }
            x = abs(x - i);
        } else {
            s[i] = dir[chy];
            if (y < i) {
                chy ^= 1;
            }
            y = abs(y - i);
        }
    }
    cout << s << endl;
    assert(x == 0 && y == 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    int d;
    cin >> d;
    for (int i = 1; i <= d; ++i) {
        cout << "Case #" << i << ":";
        alg();
    }
}
