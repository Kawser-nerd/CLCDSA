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

const char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

LL alg() {
    string s;
    int n;
    cin >> s >> n;
    int lb = -1;
    int cs = 0;
    LL res = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
        bool bad = false;
        for (int j = 0; j < 5; ++j) {
            if (s[i] == vowels[j]) {
                bad = true;
            }
        }
        if (!bad) {
            ++cs;
        } else {
            cs = 0;
        }
        if (cs >= n) {
            lb = i + 1 - n;
        }
        if (lb != -1) {
            res += lb + 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int d;
    cin >> d;
    for (int i = 1; i <= d; ++i) {
        cout << "Case #" << i << ": " << alg() << endl;
    }
}
