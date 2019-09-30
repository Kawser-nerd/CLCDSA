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

const int N = 100;

int n;
vector<pt> s[N];

int main(){
    #ifdef ssu1
    assert(freopen("input.txt", "r", stdin));
    #endif

    int tests;
    cin >> tests;
    
    forn(test, tests) {
        cin >> n;
        
        forn(i, n) {
            s[i].clear();
            
            string cur;
            cin >> cur;
            
            for (int j = 0; j < sz(cur);){
                int k = j + 1;
                while (k < sz(cur) && cur[j] == cur[k])
                    ++k;
                
                s[i].pb(pt(cur[j], k - j));
                
                j = k;
            }                                     
        }        
        
        bool good = true;
        
        forn(i, n - 1) {
            if (sz(s[i]) != sz(s[i + 1])) {
                good = false;
                break;
            }
            
            forn(j, sz(s[i]))
                if (s[i][j].X != s[i + 1][j].X) {
                    good = false;
                    break;
                }
                
            if (!good)
                break;
        }
        
        printf("Case #%d: ", test + 1);
        
        if (!good) {
            puts("Fegla Won");
            continue;
        }
        
        int ans = 0;
        
        for (int i = 0; i < sz(s[0]); ++i) {
            int add = INF;
            for (int j = 0; j < n; ++j) {
                int cur = 0;
                for (int k = 0; k < n; ++k)
                    cur += abs(s[k][i].Y - s[j][i].Y);
                    
                add = min(add, cur);
            }
            
            ans += add;
        }
        
        printf("%d\n", ans);
    }

    return 0;
}

