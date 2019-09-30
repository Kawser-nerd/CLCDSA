#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define PRINT(x)
#define PRINT_CONT(x)
#define PRINT_MSG(x)
#endif

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;


// Enlarge MSVS stack size
#pragma comment(linker, "/STACK:16777216")

#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

void initialize()
{
    freopen("0.in", "r", stdin);
    freopen("_.out", "w", stdout);
}

char move(int& v, int d, int dir) {
    char res;
    if (v > 0) {
        if (dir == 0) {
            res = 'E';
        }
        else {
            res = 'N';
        }
        v -= d;
    }
    else {
        if (dir == 0) {
            res = 'W';
        }
        else {
            res = 'S';
        }
        v += d;
    }
    return res;
}

int main()
{
    initialize();

    int x_, y_;
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        cin >> x_ >> y_;
        int sum = 0;
        for (int s = 1; ; ++s) {
            if (sum >= abs(x_) + abs(y_)) {
                std::vector<char> res;
                int x = x_;
                int y = y_;
                for (int i = s; i >= 1; --i) {
                    char c;
                    if (abs(x) > abs(y)) {
                        c = move(x, i, 0);
                    }
                    else {
                        c = move(y, i, 1);
                    }
                    //cerr << x << " " << y << endl;
                    res.push_back(c);
                    //cerr << c << " " << x << " " << y<< endl;
                }
                //cerr << endl;
                if (x == 0 && y == 0) {
                    reverse(all(res));
                    string r(all(res));
                    printf("Case #%d: %s\n", tt, r.c_str());
                    break;
                }
            }
            sum += s;
        }
    }
    
    return 0;
}
