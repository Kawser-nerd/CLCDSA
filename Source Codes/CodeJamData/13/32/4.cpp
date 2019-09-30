#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forit(i, v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair
template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = (int)1E9 + 7;
const ld EPS = 1E-9;
const ld PI = 3.1415926535897932384626433832795;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const string dc = "NSEW";

li dist(int x, int y){
    return abs(x) + abs(y);
}

bool checkIter(int x, int y, int cnt, string& ans){
    ans.clear();
    ford(iter, cnt){
        int mul = iter+1;

        int wk = -1;
        li cur = 1e18;

        forn(k, 4){
            int nx = x - dx[k]*mul;
            int ny = y - dy[k]*mul;

            if(cur > dist(nx, ny)){
                cur = dist(nx, ny);
                wk = k;
            }
        }

        x -= dx[wk]*mul;
        y -= dy[wk]*mul;
        ans += dc[wk];
    }

    reverse(all(ans));

    return (x == 0 && y == 0);
}

const int CNT = 100000;

string get(int x, int y){
    string ans;
    for1(cnt, CNT){
        if(checkIter(x, y, cnt, ans)){
            return ans;
        }
    }
    throw;
}

int main() {
    #ifdef myproject
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    #endif


//    cerr << get(0, 1) << endl;


    int tests;
    cin >> tests;
    forn(testsit, tests){
        printf("Case #%d: ", testsit+1);

        int x, y;
        cin >> x >> y;
        cout << get(x, y);

        puts("");
        //cerr << "testsit=" << testsit+1 << " " << clock() << endl;
    }
    return 0;
}


