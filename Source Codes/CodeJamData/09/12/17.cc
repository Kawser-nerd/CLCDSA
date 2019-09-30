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

typedef long long integer;

struct Crossing {
    integer ns;
    integer we;
    integer offset;
};

struct Position {
    int i, j;
    int corner;
};

struct DNode {
    Position pos;
    integer dist;
};

bool operator<(const DNode& a, const DNode& b) {
    return (a.dist < b.dist);
}
bool operator>(const DNode& a, const DNode& b) {
    return (a.dist > b.dist);
}

bool operator<(const Position& a, const Position& b) {
    if (a.i != b.i)
        return (a.i < b.i);
    if (a.j != b.j)
        return (a.j < b.j);
    return (a.corner < b.corner);
}

integer waitSignal(integer curdist, const Crossing& c, int dir) {
    integer delta = curdist - c.offset;
    integer period = c.ns + c.we;
    if (delta < 0)
        delta += ((-delta) / period + 1) * period;
    delta %= period;
    if (dir == 0) {
        if (delta < c.ns)
            return curdist;
        return curdist - delta + period;
    } else {
        if (delta >= c.ns)
            return curdist;
        return curdist - delta + c.ns;
    }
}

integer solve(const vector< vector<Crossing> >& town) {
    const int n = town.size(), m = town[0].size();
    const Position START_POSITION = {n-1, 0, 1};
    const Position GOAL_POSITION = {0, m-1, 2};

    map<Position, integer> dists;
    priority_queue<DNode, vector<DNode>, greater<DNode> > q;
    q.push((DNode){START_POSITION, 0});

    while(!q.empty()) {
        Position cur = q.top().pos;
        integer curdist = q.top().dist;
        q.pop();
        if (dists.count(cur))
            continue;
        dists[cur] = curdist;

        // walk along blocks
        REP(dir, 2) {
            Position next(cur);
            next.corner ^= 1 << dir;
            (dir == 0 ? next.i : next.j) += ((cur.corner & (1<<dir)) ? 1 : -1);
            integer nextdist = curdist + 2;
            if (0 <= next.i && next.i < n && 0 <= next.j && next.j < m)
                if (!dists.count(next))
                    q.push((DNode){next, nextdist});
        }

        // cross roads
        REP(dir, 2) {
            Position next(cur);
            next.corner ^= 1 << dir;
            integer nextdist = waitSignal(curdist, town[cur.i][cur.j], dir) + 1;
            if (!dists.count(next))
                q.push((DNode){next, nextdist});
        }
    }

    return dists[GOAL_POSITION];
}

int main() {

    int nCases;
    cin >> nCases;

    REP(iCase, nCases) {
        int n, m;
        cin >> n >> m;
        vector< vector<Crossing> > town(n, vector<Crossing>(m));
        REP(i, n) REP(j, m) {
            Crossing& c = town[i][j];
            cin >> c.ns >> c.we >> c.offset;
        }
        cout << "Case #" << iCase+1 << ": " << solve(town) << endl;
    }

    return 0;
}
