#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))

#define fabsl __builtin_fabsl
#define atan2l __builtin_atan2l
#define cosl __builtin_cosl
#define sinl __builtin_sinl
#define sqrtl __builtin_sqrtl

struct Tile {
    int x, y;
    char color;
};

const int INF = (int) 1e9;

void alg() {
    int n;
    cin >> n;

    vector<Tile> tiles(n);

    for (int i = 0; i < n; ++i) {
        cin >> tiles[i].x >> tiles[i].y >> tiles[i].color;
    }
    int cx = INF;
    int cy = INF;
    for (int x = -500; x <= 500; ++x) {
        for (int y = -500; y <= 500; ++y) {
            FORE (it, tiles) {
                int dist = max(abs(it->x - x), abs(it->y - y));
                char expe = (dist % 2) ? '#' : '.';
                if (it->color != expe) {
                    goto bad;
                }
            }
            if (abs(x) + abs(y) < abs(cx) + abs(cy) || (abs(x) + abs(y) == abs(cx) + abs(cy) && (x > cx || (x == cx && y > cy)))) {
                cx = x;
                cy = y;
            }
            bad:{}
        }
    }
    if (cx == INF) {
        cout << "Too damaged" << endl;
    } else {
        cout << cx << " " << cy << endl;
    }
}

int main() {
    int d;
    cin >> d;
    for (int test_case = 1; test_case <= d; ++test_case) {
        cout << "Case #" << test_case << ": ";
        alg();
    }
}
