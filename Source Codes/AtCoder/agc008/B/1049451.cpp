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

#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")"  << " " << __FILE__ << endl;

signed main(void) {
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    VI a(n);
    REP(i, n) {
        cin >> a[i];
    }

    int ans = 0;
    REP(i, n) {
        if (a[i] > 0) {
            ans += a[i];
        }
    }

    int pos = 0, neg = 0;
    REP(i, k) {
        if (a[i] > 0) {
            pos += a[i];
        } else {
            neg += a[i];
        }
    }
    int posmin = pos, negmax = neg;
    FOR(i, k, n) {
        if (a[i] > 0) {
            pos += a[i];
        } else {
            neg += a[i];
        }
        if (a[i - k] > 0) {
            pos -= a[i - k];
        } else {
            neg -= a[i - k];
        }
        posmin = min(posmin,pos);
        negmax = max(negmax,neg);
    }

    cout << max(ans-posmin,ans+negmax) << endl;

    return 0;
}