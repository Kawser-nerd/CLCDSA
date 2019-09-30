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

int solve_strict(vector<int> v) {
    int n = v.size();
    if (n == 0)
        return 0;
    int k = 0;
    while(v[k] != n-1)
        k++;
    int cost = (n-1)-k;
    for(int i = k+1; i < n; i++)
        v[i-1] = v[i];
    v.pop_back();
    return cost + solve_strict(v);
}

int solve_small(vector<int> v) {
    int n = v.size();
    vector<int> perm(n);
    REP(i, n)
        perm[i] = i;
    int mini = 100000;
    do {
        bool ok = true;
        REP(i, n) {
            if (v[perm[i]] > i) {
                ok = false;
                break;
            }
        }
        if (ok)
            mini = min(mini, solve_strict(perm));
    } while(next_permutation(ALLOF(perm)));
    return mini;
}

int solve_large(vector<int> v) {
    int n = v.size();
    if (n == 0)
        return 0;
    int k = 0;
    while(v[k] >= 1)
        k++;
    int cost = k;
    v.erase(v.begin()+k);
    n--;
    REP(i, n)
        v[i]--;
    return cost + solve_large(v);
}

int solve(vector<int> v) {
    return solve_large(v);
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
        vector<int> v(n);
        REP(i, n) {
            int k = -1;
            REP(j, n) {
                char x;
                cin >> x;
                if (x == '1')
                    k = j;
            }
            v[i] = k;
        }
        cout << "Case #" << iCase+1 << ": " << solve(v) << endl;
    }

    return 0;
}
