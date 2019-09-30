#ifdef ssu1
#define _GLIBCXX_DEBUG
#define _DEBUG_ 1
#else
#define _DEBUG_ 0
#endif

#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <bitset>
#include <sstream>

using namespace std;

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define X first
#define Y second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define db(x) if(_DEBUG_){ cout << __FUNCTION__ << "(" << __LINE__ << "): " << #x << " = " << x << endl; }
#define dbi(x, y) if(_DEBUG_){ cout << __FUNCTION__ << "(" << __LINE__ << "): [" << #x << "] ~ [" << #y << "]\n"; for(typeof(x) i = x; i != y; ++i) { cout << *(i) << " "; } cout << endl; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9) + 7;
const ld PI = acosl(ld(-1));
const ld EPS = 1e-9;

const int L = 31;

int a, b, k;

inline int getBit(int mask, int i) {
    return (mask >> i) & 1;   
}

inline void setupLfRg(int& lf, int& rg, int was, int mask, int i) {
    lf = 0;
    rg = 1;
    
    if (was && getBit(mask, i) == 0)
        rg = 0;
}

li z[2][2][2][L];

inline li solve(int wa, int wb, int wk, int pos) {
    if (pos < 0) {
        return !wa && !wb && !wk;
    }
    
    li& res = z[wa][wb][wk][pos];
    
    if (res == -1) {
        res = 0;
    
        int lfA, rgA, lfB, rgB, lfK, rgK;
        setupLfRg(lfA, rgA, wa, a, pos);
        setupLfRg(lfB, rgB, wb, b, pos);
        setupLfRg(lfK, rgK, wk, k, pos);                
        
        for (int ca = lfA; ca <= rgA; ++ca)
        for (int cb = lfB; cb <= rgB; ++cb) {
            int ck = (ca & cb);
            
            if (lfK <= ck && ck <= rgK) {
                int nwa = (wa && ca == getBit(a, pos));
                int nwb = (wb && cb == getBit(b, pos));            
                int nwk = (wk && ck == getBit(k, pos));                            
                
                res += solve(nwa, nwb, nwk, pos - 1);
            }
        }
    }
    
    return res;
}

int main(){
    #ifdef ssu1
    assert(freopen("input.txt", "r", stdin));
    #endif

    int tests;
    cin >> tests;
    
    forn(test, tests) {
        cin >> a >> b >> k;
        memset(z, -1, sizeof(z));
        printf("Case #%d: %lld\n", test + 1, solve(1, 1, 1, L - 1));
    }

    return 0;
}

