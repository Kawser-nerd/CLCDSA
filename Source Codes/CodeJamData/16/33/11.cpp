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
const int a = 239;
const int b = 17;
const int c = 23;

vector <pair <pair <int, int>, int> > genall(int j, int p, int s, int k) {
    vector <pair <pair <int, int>, int> > ans;
    for (int q1 = 0; q1 < j; q1++)
        for (int q2 = 0; q2 < p; q2++)
            for (int q3 = 0; q3 < min(s, k); q3++) {
                ans.pb(mp(mp(q1, q2), (a * q1 + b * q2 + c * q3) % s));
            }        

    return ans;
}

bool check(int j, int p, int s, int k, vector <pair <pair <int, int>, int> > ans) {
    cerr << "I have " << j << ' ' << p << ' ' << s << ' ' << k << ' ' << (int) ans.size() << endl;
    map <pair <int, int>, int> c1, c2, c3;
    for (auto& e : ans) {
        c1[e.fs]++;
        c2[mp(e.fs.fs, e.sc)]++;
        c3[mp(e.fs.sc, e.sc)]++;
    }

    bool flag = (int) ans.size() == j * p * min(s, k);
    for (auto& e : c1) {
        flag = flag && (e.sc <= k);    
    }
    for (auto& e : c2) {
        flag = flag && (e.sc <= k);    
    }
    for (auto& e : c3) {
        flag = flag && (e.sc <= k);    
    }

    return flag;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    /*
    int lim = 10;
    for (int i = 1; i <= lim; i++)
        for (int j = i; j <= lim; j++)
            for (int k = j; k <= lim; k++)
                for (int h = 1; h <= lim; h++) {
                    assert(check(i, j, k, h, genall(i, j, k, h)));

                    cerr << i << ' ' << j << ' ' << k << ' ' << h << endl;
                }
                    
      */
    
    int tc;
    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
        int j, p, s, k;
        cin >> j >> p >> s >> k;

        cout << "Case #" << tnum + 1 << ": " << j * p * min(s, k) << endl;
        vector <pair <pair <int, int>, int> > ans = genall(j, p, s, k);

        assert((int) ans.size() == j * p * min(s, k));

        for (auto& e : ans)
            cout << e.fs.fs + 1 << ' ' << e.fs.sc + 1 << ' ' << e.sc + 1 << endl; 
    }
    

    return 0;
}