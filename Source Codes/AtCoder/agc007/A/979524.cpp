#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

using P = pair<int,int>;

int H, W;
vector<string> cells;

bool is_valid(P& p) {
    int x = p.first;
    int y = p.second;
    return 0 <= x && x <= W-1 && 0 <= y && y <= H-1;
}

bool is_passed(P& p) {
    int x = p.first;
    int y = p.second;
    return cells[y][x] == '#';
}

int main(void)
{
    cin.sync_with_stdio(false);
    cin >> H >> W;
    cells.resize(H);
    REP(h,H) cin >> cells[h];

    P prev{-1,-1};
    P p{0,0};
    P goal{W-1,H-1};
    cells[p.second][p.first] = '.';
    bool ok = true;
    while(p != goal) {
        P p_r = p; p_r.first += 1; 
        bool move = false;
        while (is_valid(p_r) && is_passed(p_r)) {
            cells[p_r.second][p_r.first] = '.';
            p = p_r;
            move = true;
        }
        P p_d = p; p_d.second += 1; 
        while (is_valid(p_d) && is_passed(p_d)) {
            cells[p_d.second][p_d.first] = '.';
            p = p_d;
            move = true;
        }
        if (!move) {
            ok = false;
            break;
        }
    }
    REP(h,H) {
        REP(w,W) {
            P p{w,h};
            if (is_passed(p)) ok = false;
        }
    }

    if (ok) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    
    return 0;
}