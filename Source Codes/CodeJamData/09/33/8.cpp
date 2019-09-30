#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cassert>
#include <utility>

using namespace std;

#define EPS 1E-8

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, a) for (int i = 0; i < int(a.size()); i++)
#define fors(i, a) for (int i = 0; i < int(a.length()); i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define VS vector<string>

#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

#define C_IN_FILE "input.txt"
#define C_OUT_FILE "output.txt"

vector<int> a;
int n, m;
const int NMAX = 222;
int d[NMAX][NMAX];

void outdata() {
}

int calc(int l, int r) {
    int& res = d[l][r];
    if (res != -1) {
        return res;
    }
    if (l + 1 == r) {
        return res = 0;        
    }
    int add = a[r] - a[l] - 2;
    res = 1000000000;
    for(int i = l + 1; i < r; ++i) {
        res = min(res, calc(l, i) + calc(i, r) + add);
    }
    return res;
}

void solve() {
    cin >> n >> m;
    a.clear();
    a.push_back(0);
    forn(i, m) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    a.push_back(n + 1);
    memset(d, 255, sizeof(d));
    cout << calc(0, m + 1) << endl;
}

void readdata() {
}

int main() {
    int tst;
    cin >> tst;
    forn(i, tst) {
        cout << "Case #" << i + 1 << ": ";
        readdata();
	    solve();
    	outdata();
    }
	return 0;
}
