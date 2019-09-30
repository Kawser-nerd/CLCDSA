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
#define ALL(a) (a).begin(), (a).end()
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

#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")"  << " " << __FILE__ << endl;

signed main(void) {
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    cin.tie(0);

    int n;
    cin >> n;
    VI s(n);
    REP(i, n) {
        char c;
        cin >> c;
        s[i] = (c == 'o' ? 0 : 1);
    }

    REP(x, 2) {
        REP(y, 2) {
            bool f = true;
            VI ans(n);
            ans[0] = x;
            ans[1] = y;
            int t;
            FOR(i, 2, n+2) {
                if (s[(i - 1)%n] == 0) {
                    if (ans[(i - 1)%n] == 0) {
                        t = 0;
                    } else {
                        t = 1;
                    }
                } else {
                    if (ans[(i - 1)%n] == 0) {
                        t = 1;
                    } else {
                        t = 0;
                    }
                }
                if(i<n){
                    ans[i] = (ans[(i - 2)%n] + t) % 2;
                }else{
                    if(ans[i%n] != (ans[(i - 2)%n] + t) % 2){
                        f = false;
                    }
                }
            }
            if(f){
                REP(i,n){
                    cout << (ans[i]==0?'S':'W');
                }
                cout << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}