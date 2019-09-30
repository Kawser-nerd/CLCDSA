#define _ijps 01
#define _CRT_SECURE_NO_DEPRECATE
//#pragma comment(linker, "/STACK:667772160")
#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h> 
#include <list>
#include <cstring>
#include <queue>
using namespace std;

#define name ""
#define times clock() * 1.0 / CLOCKS_PER_SEC

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

struct __isoff {
    __isoff() {
        if(_ijps)
            freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);//, freopen("test.txt", "w", stderr);
        //else freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);
        //ios_bsume::sync_with_stdio(0);
        //srand(time(0));
        srand('C' + 'T' + 'A' + 'C' + 'Y' + 'M' + 'B' + 'A');
    }
    ~__isoff() {
        //if(_ijps) cout<<times<<'\n';
    }
} __osafwf;
const ull p1 = 131;
const ull p2 = 129;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int infi = 1e9 + 7;
const ll inf = 1e18 + 7;
const ll dd = 5e5 + 7;

typedef long long ll;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, a, n) for(int i = a; i < n; i++)
#define times clock() * 1.0 / CLOCKS_PER_SEC

const int all_time = 24 * 60;

bool ok(vector<double> const& T, double t, double s) {
    for(int i = 0; i < T.size(); i++) {
        if(T[i] < s) {
            t -= s - T[i];
        }
    }
    return t >= 0;
}

int main() {
    int t;
    cin >> t;
    for(int ii = 1; ii <= t; ii++) {
        int n, k;
        double t;
        cin >> n >> k >> t;
        vector<double> P(n);
        for(int i = 0; i < n; i++) {
            cin >> P[i];
        }
        double l = 0, r = 1;
        for(int j = 0; j < 100; j++) {
            double s = (l + r) / 2;
            if(ok(P, t, s)) {
                l = s;
            }
            else {
                r = s;
            }
        }
        double res = 1;
        for(int i = 0; i < n; i++) {
            res *= max(l, P[i]);
        }
        printf("Case #%d: %0.10f\n", ii, res);
    }
}