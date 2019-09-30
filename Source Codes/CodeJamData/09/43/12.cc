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

vector< vector<int> > g;
int n, m;

vector<bool> visited, matched;
vector<int> levels, matching;

bool augment(int left) {
    if (left == n)
        return true;
    if (visited[left])
        return false;
    visited[left] = true;
    REP(i, g[left].size()) {
        int right = g[left][i];
        int next = matching[right];
        if (levels[next] > levels[left] && augment(next)) {
            matching[right] = left;
            return true;
        }
    }
    return false;
}

int match() {
    matching.assign(m, n);
    matched.assign(n, false);
    bool cont;
    do {
        levels.assign(n+1, -1);
        levels[n] = n;
        queue<int> q;
        REP(left, n) {
            if (!matched[left]) {
                q.push(left);
                levels[left] = 0;
            }
        }
        while(!q.empty()) {
            int left = q.front();
            q.pop();
            REP(i, g[left].size()) {
                int right = g[left][i];
                int next = matching[right];
                if (levels[next] < 0) {
                    levels[next] = levels[left] + 1;
                    q.push(next);
                }
            }
        }
        visited.assign(n, false);
        cont = false;
        REP(left, n)
            if (!matched[left] && augment(left))
                matched[left] = cont = true;
    } while(cont);
    return count(ALLOF(matched), true);
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
        int k;
        cin >> n >> k;
        vector< vector<int> > charts(n, vector<int>(k));
        REP(i, n) REP(j, k)
            cin >> charts[i][j];
        m = n;
        g.clear();
        g.resize(n);
        REP(i, n) REP(j, n) {
            bool ok = true;
            REP(l, k)
                if (charts[i][l] <= charts[j][l])
                    ok = false;
            if (ok)
                g[i].push_back(j);
        }
        printf("Case #%d: %d\n", iCase+1, n-match());
    }

    return 0;
}
