#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;

using std::fixed;
using std::setprecision;
using std::setw;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

int main() {
    int deg, dis;
    cin >> deg >> dis;
    deg *= 10;

    string dir = "undef";
    if (16875 <= deg && deg < 19125) {
        dir = "S";
    } else if (1125 <= deg && deg < 3375) {
        dir = "NNE";
    } else if (19125 <= deg && deg < 21375) {
        dir = "SSW";
    } else if (3375 <= deg && deg < 5625) {
        dir = "NE";
    } else if (21375 <= deg && deg < 23625) {
        dir = "SW";
    } else if (5625 <= deg && deg < 7875) {
        dir = "ENE";
    } else if (23625 <= deg && deg < 25875) {
        dir = "WSW";
    } else if (7875 <= deg && deg < 10125) {
        dir = "E";
    } else if (25875 <= deg && deg < 28125) {
        dir = "W";
    } else if (10125 <= deg && deg < 12375) {
        dir = "ESE";
    } else if (28125 <= deg && deg < 30375) {
        dir = "WNW";
    } else if (12375 <= deg && deg < 14625) {
        dir = "SE";
    } else if (30375 <= deg && deg < 32625) {
        dir = "NW";
    } else if (14625 <= deg && deg < 16875) {
        dir = "SSE";
    } else if (32625 <= deg && deg < 34875) {
        dir = "NNW";
    } else {
        dir = "N";
    }

    int win = dis * 100 / 60;
    win = (win / 10) + (win % 10 >= 5 ? 1 : 0);

    int w = -1;
    if (0 <= win && win <= 2) {
        w = 0;
    } else if (3 <= win && win <= 15) {
        w = 1;
    } else if (16 <= win && win <= 33) {
        w = 2;
    } else if (34 <= win && win <= 54) {
        w = 3;
    } else if (55 <= win && win <= 79) {
        w = 4;
    } else if (80 <= win && win <= 107) {
        w = 5;
    } else if (108 <= win && win <= 138) {
        w = 6;
    } else if (139 <= win && win <= 171) {
        w = 7;
    } else if (172 <= win && win <= 207) {
        w = 8;
    } else if (208 <= win && win <= 244) {
        w = 9;
    } else if (245 <= win && win <= 284) {
        w = 10;
    } else if (285 <= win && win <= 326) {
        w = 11;
    } else {
        w = 12;
    }

    cout << (w == 0 ? "C" : dir) << " " << w << endl;


    return 0;
}