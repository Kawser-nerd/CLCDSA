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
    freopen("large.in", "r", stdin);
    freopen("_.out", "w", stdout);
}

bool isCons(char c) {
    return !(c == 'i' || c == 'o' || c == 'a' || c == 'e' || c == 'u');
}

int main()
{
    initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        std::string str;
        int k;
        cin >> str >> k;

        int64 res = 0;
        int cons = 0;
        int pos = -1;
        for (int i = 0; i < str.length(); ++i) {
            if (isCons(str[i])) {
                cons += 1;
            }
            else {
                cons = 0;
            }
            if (cons >= k) {
                pos = i - k + 1;
            }
            if (pos != -1) {
                res += pos + 1;
            }
        }
        cout << "Case #" << tt << ": " << res << "\n";
    }
    
    return 0;
}
