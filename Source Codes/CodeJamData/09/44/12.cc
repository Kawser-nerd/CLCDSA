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

typedef complex<double> P;

istream& operator>>(istream& is, P& p) {
    double x, y;
    is >> x >> y;
    p = P(x, y);
    return is;
}

struct C {
    P p;
    double r;
};

double enclose(C c1, C c2) {
    return (abs(c1.p-c2.p) + c1.r + c2.r) / 2;
}

double solve(vector<C> v) {
    int n = v.size();
    if (n == 1) {
        return v[0].r;
    }
    else if (n == 2) {
        return max(v[0].r, v[1].r);
    }
    else if (n == 3) {
        double mini = 1e100;
        REP(i, 3) {
            int j = (i+1)%3;
            int k = (i+2)%3;
            mini = min(mini, max(enclose(v[i], v[j]), v[k].r));
        }
        return mini;
    }
    else {
        // not yet implemented
        return -1;
    }
}

int main() {

    int nCases;
    {
        string s;
        getline(cin, s);
        istringstream is(s);
        is >> nCases;
    }

    REP(iCase, nCases) {
        int n;
        cin >> n;
        vector<C> v(n);
        REP(i, n) {
            C& c = v[i];
            cin >> c.p >> c.r;
        }
        printf("Case #%d: %.10f\n", iCase+1, solve(v));
    }

    return 0;
}
