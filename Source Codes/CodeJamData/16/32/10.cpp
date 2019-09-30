#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tc;

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
        int b;
        long long m;
        cin >> b >> m;

        cout << "Case #" << tnum + 1 << ": ";
        if ((1ll << (b - 2)) < m)
            cout << "IMPOSSIBLE" << endl;
        else {
            cout << "POSSIBLE" << endl;
            for (int i = 1; i <= b; i++) {
                int s = 0;
                if (i > 1 && i < b && (1ll << (b - i - 1) <= m)) {
                    s = 1;
                    m -= (1ll << (b - i - 1));
                } 
                if (i == b && m > 0) {
                    s = 1;
                    m--;
                }

                cout << s;
            }
            cout << endl;

            assert(m == 0ll);
            
            for (int i = 2; i <= b; i++) {
                for (int j = 1; j <= b; j++) {
                    cout << int(i < j);
                }
                cout << endl;
            }
        }
    }

    return 0;
}