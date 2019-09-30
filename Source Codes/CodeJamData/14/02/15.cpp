#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <complex>
#include <stack>
#include <iomanip>

using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;

int main() {
    int N;
    cin >> N;
    for(int z=1; z<=N; z++) {
        cout << "Case #" << z << ": ";
        long double c, f, x; cin >> c >> f >> x;
        long double t = x/2, _t, tf = 0, r = 2;
        do {
            _t = t;
            tf = tf + c/r; // time to get the requisite number of farms
            r += f;        // rate after getting this many farms
            t = tf + x/r; // time to get x things
        } while(_t > t);
        cout << fixed << setprecision(9) << _t << endl;
    }
    return 0;    
}
