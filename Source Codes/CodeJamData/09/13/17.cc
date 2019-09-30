// Powered by FTH

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <functional>
#include <utility>
#include <numeric>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALLOF(c) ((c).begin()), ((c).end())

typedef long double decimal;

decimal choose(int n, int c) {
    decimal res = 1;
    REP(i, c)
        res *= n-i;
    REP(i, c)
        res /= i+1;
    return res;
}

decimal solve(int n, int c) {
    decimal pall = choose(n, c);
    vector<decimal> dp(n+1);
    dp[n] = 0;
    for(int k = n-1; k >= 0; k--) {
        decimal sum = 0;
        for(int t = 1; t <= c; t++) {
            if (c-t > k || t > n-k)
                continue;
            sum += choose(k, c-t) * choose(n-k, t) * dp[k+t];
        }
        decimal p0 = 0;
        if (k >= c)
            p0 = choose(k, c);
        dp[k] = (pall + sum) / (pall - p0);
    }
    return dp[0];
}


int main() {

    int nCases;
    cin >> nCases;

    REP(iCase, nCases) {
        int n, c;
        cin >> n >> c;
        printf("Case #%d: %.10f\n", iCase+1, (double)solve(n, c));
    }

    return 0;
}
