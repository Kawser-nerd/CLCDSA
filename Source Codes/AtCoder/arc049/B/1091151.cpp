#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>

#define FOR(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)

using namespace std;

bool check(double half, vector<int> &xx, vector<int> &yy, vector<int> &cc) {
    double lbx = -100000.0, ubx = 100000.0;
    double lby = -100000.0, uby = 100000.0;
    int n = xx.size();
    FOR(i, 0, n) {
        int x = xx[i], y = yy[i], c = cc[i];
        double t_lbx = x - (half / c), t_ubx = x + (half / c);
        double t_lby = y - (half / c), t_uby = y + (half / c);
        lbx = max(lbx, t_lbx);
        lby = max(lby, t_lby);
        ubx = min(ubx, t_ubx);
        uby = min(uby, t_uby);
    }
    bool first = (abs(ubx - lbx) < 1e-10) || lbx < ubx;
    bool second = (abs(uby - lby) < 1e-10) || lby < uby;

    return first && second;
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n), c(n);
    FOR(i, 0, n) {
        cin >> x[i] >> y[i] >> c[i];
    }
    // double????????????
    double lb = 0, ub = 100000000.0;
    FOR(i, 0, 100) {
        double half = (lb + ub) / 2.0;
        if (check(half, x, y, c)) {
            ub = half;
        }
        else
            lb = half;
    }
    printf("%.14f\n", ub);

    return 0;
}