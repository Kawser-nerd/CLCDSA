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

#include <gmp.h>
#include <gmpxx.h>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALLOF(c) ((c).begin()), ((c).end())

typedef complex<int> P;

namespace std {
    bool operator<(const P& a, const P& b) {
        return make_pair(a.real(), a.imag()) < make_pair(b.real(), b.imag());
    }
}

const P ADJ[4] = {
    P(1, 0),
    P(-1, 0),
    P(0, 1),
    P(0, -1),
};

P skip(const set<P>& field, P p, P dir) {
    while(field.count(p+dir) > 0)
        p += dir;
    return p;
}

void solve_case() {

    P start, goal;
    set<P> field;
    int h, w;
    cin >> h >> w;

    REP(i, h) REP(j, w) {
        char c;
        cin >> c;
        if (c == '#') {
            // do nothing
        }
        else {
            field.insert(P(i, j));
            if (c == 'O')
                start = P(i, j);
            if (c == 'X')
                goal = P(i, j);
        }
    }

    map<P, vector<P> > adj;
    FOR(it, field) {
        P p = *it;
        REP(diri, 4)
            adj[p].push_back(skip(field, p, ADJ[diri]));
    }

    map< pair<P, P>, int > dists;
    queue< pair<P, P> > q;

    FOR(it, adj[start]) {
        P wall = *it;
        if (dists.count(make_pair(start, wall)) == 0) {
            dists[make_pair(start, wall)] = 0;
            q.push(make_pair(start, wall));
        }
    }

    int res = -1;
    while(!q.empty()) {
        pair<P,P> cur = q.front();
        q.pop();
        if (cur.first == goal) {
            res = dists[cur];
            break;
        }
        REP(diri, 4) {
            P dir = ADJ[diri];
            P nextpos = (field.count(cur.first+dir) > 0 ? cur.first+dir : cur.second);
            FOR(it, adj[nextpos]) {
                pair<P, P> next(nextpos, *it);
                if (dists.count(next) == 0) {
                    dists[next] = dists[cur] + 1;
                    q.push(next);
                }
            }
            {
                pair<P, P> next(nextpos, cur.second);
                if (dists.count(next) == 0) {
                    dists[next] = dists[cur] + 1;
                    q.push(next);
                }
            }
        }
    }

    if (res < 0)
        cout << "THE CAKE IS A LIE" << endl;
    else
        cout << res << endl;
}


int main() {

    int nCases;
    cin >> nCases;

    REP(iCase, nCases) {
        cout << "Case #" << iCase+1 << ": ";
        solve_case();
    }

    return 0;
}
