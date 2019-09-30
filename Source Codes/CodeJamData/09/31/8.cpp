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

string s;

void outdata() {
}

void solve() {
    string q = s;
    norm(q);
    long long base = (int)q.size(), res = 0;
    if (base == 1) base = 2;
    map<char, long long> w;
    vector<bool> used((int)base, false);
    fors(i, s) {
        char c = s[i];
        if (w.count(c) == 0) {
            size_t st = i == 0 ? 1 : 0;
            long long r = -1;
            for(size_t j = st; j < used.size(); ++j) if (!used[j]) {
                r = j;
                used[j] = true;
                break;
            }
            w[c] = r;
        }
        res = res * base + w[c];
    }
    cout << res << endl;
}

void readdata() {
    cin >> s;
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
