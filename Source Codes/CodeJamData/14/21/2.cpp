#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string.h>
#include <queue>
#include <cstdio>
#include <cassert>
#include <deque>
#include <stack>
#include <utility>
#include <numeric>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

void compress(string s, string& c, vector<int>& lens) {
    int l = 0;
    while (l < s.size()) {
        int r = l;
        while (r < s.size() && s[l] == s[r]) r++;
        c += s[l];
        lens.pb(r - l);
        l = r;
    }
}

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n;
    cin >> n;
    vector<string> s(n);
    forn(i, n) {
        cin >> s[i];
    }
    vector< vector<int> > lens(n);
    vector<string> compr(n);
    forn(i, n) {    
        compress(s[i], compr[i], lens[i]);
        if (compr[i] != compr[0]) {
            cout << "Fegla Won" << endl;
            return;
        }
    }
    int ans = 0;
    forv(i, compr[0]) {
        int mn = 1e9;
        for (int len = 1; len <= 100; len++) {
            int cur = 0;
            forn(j, n) cur += abs(len - lens[j][i]);
            mn = min(mn, cur);
        }        
        ans += mn;
    }
    cout << ans << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    forn(i, tc) solve(i + 1);
    return 0;
}
