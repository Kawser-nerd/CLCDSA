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
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
 
#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define Aint(a) (a).begin(), (a).end()
#define PB push_back
#define MP make_pair
#define FST first
#define SND second
#define SZ(a) (signed)((a).size())
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())
 
using namespace std;
 
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
 
const int MOD = 1000000007;
const char ENDL = '\n';
 
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")"  << " " << __FILE__ << endl;
 
int modPow(int x, int p, int mod) {
    int ret = 1;
    while (p > 0) {
        if (p & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return ret;
}
 
class modCombination {
    vector<int> x, xi;
 
public:
    modCombination(int max) : x(max + 1), xi(max + 1) {
        x[0] = 0;
        x[1] = 1;
        for (int i = 2; i <= max; ++i) {
            x[i] = x[i - 1] * i % MOD;
        }
        xi[0]=1;
        for (int i = 1; i <= max; ++i) {
            xi[i] = modPow(x[i],MOD-2,MOD);
        }
    }
 
    int combination(int n,int r){
        return ((x[n]*xi[r]) % MOD) *xi[n-r] % MOD;
    }
};
 
signed main(void) {
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    cin.tie(0);
 
    int h, w, a, b;
    cin >> h >> w >> a >> b;
 
    modCombination c(h+w+2);
 
    int ans = 0;
    REP(i, min(h - a, w - b)) {
        ans += c.combination(h - a - i - 1 + b + i, b + i) * c.combination(a + i + w - b - i - 1, w - b - i - 1) % MOD;
        ans %= MOD;
    }
 
    cout << ans << ENDL;
 
    return 0;
}