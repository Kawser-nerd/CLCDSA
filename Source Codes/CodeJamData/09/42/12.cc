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
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALLOF(c) ((c).begin()), ((c).end())

const int INF = 100000;

int h, w, f;
char field[64][64];

struct Param {
    int ci, cj, digl, digr;
};

bool operator<(const Param& a, const Param& b) {
    if (a.ci != b.ci)
        return (a.ci < b.ci);
    if (a.cj != b.cj)
        return (a.cj < b.cj);
    if (a.digl != b.digl)
        return (a.digl < b.digl);
    if (a.digr != b.digr)
        return (a.digr < b.digr);
    return false;
}

map<Param, int> memo;

int search(int ci, int cj, int digl, int digr);

int fall(int ci, int cj, int digl, int digr) {
    int d = 0;
    while(field[ci+1][cj] == '.' || (d == 0 && digl <= cj && cj < digr)) {
        d++;
        ci++;
    }
    if (d > 1)
        digl = digr = 0;
    if (d > f)
        return INF;
    return search(ci, cj, digl, digr);
}

int search(int ci, int cj, int digl, int digr) {
    if (ci == h-1)
        return 0;
    const Param param = {ci, cj, digl, digr};
    if (memo.count(param) == 0) {
        int res = INF;
        char row[64];
        REP(j, w)
            row[j] = field[ci][j];
        for(int j = digl; j < digr; j++)
            row[j] = '.';
        int rockl = cj, rockr = cj;
        while(row[rockl-1] == '.' && field[ci+1][rockl-1] == '#')
            rockl--;
        while(row[rockr+1] == '.' && field[ci+1][rockr+1] == '#')
            rockr++;
        if (row[rockl-1] == '.')
            res = min(res, 0 + fall(ci, rockl-1, 0, 0));
        if (row[rockr+1] == '.')
            res = min(res, 0 + fall(ci, rockr+1, 0, 0));
        for(int new_digl = rockl; new_digl <= rockr; new_digl++) {
            for(int new_digr = new_digl+1; new_digr <= rockr+1; new_digr++) {
                if (row[new_digl-1] == '.' && field[ci+1][new_digl-1] == '#')
                    res = min(res, new_digr-new_digl + fall(ci, new_digl, new_digl, new_digr));
                if (row[new_digr] == '.' && field[ci+1][new_digr] == '#')
                    res = min(res, new_digr-new_digl + fall(ci, new_digr-1, new_digl, new_digr));
            }
        }
        memo[param] = res;
    }
    return memo[param];
}

int solve() {
    return search(0, 1, 0, 0);
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
        memo.clear();
        cin >> h >> w >> f;
        memset(field, '#', sizeof(field));
        REP(i, h) REP(j, w)
            cin >> field[i][j+1];
        w += 2;
        cout << "Case #" << iCase+1 << ": ";
        int res = solve();
        if (res >= INF)
            cout << "No" << endl;
        else
            cout << "Yes " << res << endl;
    }

    return 0;
}
