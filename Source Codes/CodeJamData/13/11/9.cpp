#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef unsigned long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int main()
{
    int T;
    cin >> T;

    for (int CN = 1; CN <= T; ++CN) {
        Int r, t;
        cin >> r >> t;

        Int lo = 1, hi = 2000000000LL;
        while (hi - lo > 1) {
            Int mid = (hi + lo) / 2;

            if (2*r - 1 + 2*mid > t / mid + 1) {
                hi = mid;
            } else if (mid * (2*r - 1 + 2*mid) <= t) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        cout << "Case #" << CN << ": " << lo << endl;
    }

    return 0;
}
