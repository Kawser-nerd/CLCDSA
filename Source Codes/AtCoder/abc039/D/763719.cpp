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

bool isW(char ch) {
    return ch == '.';
}

bool isB(char ch) {
    return ch == '#';
}

#define EXPAND { \
if (isW(src[h][w]) && isB(src[h2][w2])) dst[h2][w2] = '.'; \
if (isB(src[h][w]) && isW(src[h2][w2])) dst[h][w] = '.'; \
}

vector<string> expand_white(vector<string>& src) {
    auto dst = src;
    int H = SIZE(src);
    int W = SIZE(src[0]);

    REP(h,H) {
        REP(w,W) {
            int w2 = w+1;
            int h2 = h;
            if (w2 < W) {
                EXPAND
            }

            w2 = w;
            h2 = h+1;
            if (h2 < H) {
                EXPAND
            }

            w2 = w+1;
            h2 = h+1;
            if (w2 < W && h2 < H) {
                EXPAND
            }

            w2 = w-1;
            h2 = h+1;
            if (w2 >= 0 && h2 < H) {
                EXPAND
            }
        }
    }
    return dst;
}

vector<string> reverse_color(vector<string>& src) {
    auto dst = src;
    int H = SIZE(src);
    int W = SIZE(src[0]);
    REP(h,H) REP(w,W) dst[h][w] = isW(src[h][w]) ? '#' : '.'; 
    return dst;
}

vector<string> expand_black(vector<string>& src) {
    vector<string> rev = reverse_color(src);
    auto tmp = expand_white(rev);
    return reverse_color(tmp);
}


int main(void)
{
    cin.sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    vector<string> cells(H);
    REP(h,H) cin >> cells[h];

    auto white_expanded = expand_white(cells);
    auto black_expanded = expand_black(white_expanded);
    if (cells == black_expanded) {
        cout << "possible" << endl;
        for(auto& l : white_expanded) {
            cout << l << endl;
        }
    }
    else {
        cout << "impossible" << endl;
    }

    return 0;
}