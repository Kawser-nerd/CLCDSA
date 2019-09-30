#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef vector<char> vc;
typedef vector<vector<char> > vvc;
typedef vector<double> vd;
typedef vector<vector<double> > vvd;
template<class T> using vv=vector<vector< T > >;
typedef deque<int> di;
typedef deque<deque<int> > ddi;
typedef deque<bool> db;
typedef deque<deque<bool> > ddb;

// cout pair
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {
    s << p.first << " " << p.second << "\n"; return s;
}

// cout vector<pair>
template<typename T1, typename T2> ostream& operator<<(ostream& s, const vector<pair<T1, T2> >& vp) {
    int len = vp.size(); s << "\n";
    for (int i = 0; i < len; ++i) { s << vp[i]; }
    s << "\n"; return s;
}

// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
    int len = v.size(); s << "\n";
    for (int i = 0; i < len; ++i) {
        s << v[i]; if (i < len - 1) s << "\t";
    }
    s << "\n"; return s;
}

// cout deque
template<typename T> ostream& operator<<(ostream& s, const deque<T>& v) {
    int len = v.size(); s << "\n";
    for (int i = 0; i < len; ++i) {
        s << v[i]; if (i < len - 1) s << "\t";
    }
    s << "\n"; return s;
}

// cout 2-dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
    int len = vv.size();
    for (int i = 0; i < len; ++i) { s << vv[i]; }
    return s;
}

// cout 2-dimentional deque
template<typename T> ostream& operator<<(ostream& s, const deque< deque<T> >& vv) {
    int len = vv.size();
    for (int i = 0; i < len; ++i) { s << vv[i]; }
    return s;
}

int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    if (n == 0) {
        printf("%lld\n", (h - 2) * (w - 2));
        rep (i, 9) {
            printf("0\n");
        }
        return 0;
    }
    vector<pii> ab(n);
    rep (i, n) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        ab[i] = mp(a, b);
    }
    map<pii, int> nuri;
    vector<pii> al = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    rep (i, n) {
        int y, x;
        rep (j, 9) {
            y = ab[i].fst + al[j].fst;
            x = ab[i].snd + al[j].snd;
            if (y <= 0 || x <= 0 || y >= h - 1 || x >= w - 1) {
                continue;
            }
            nuri[mp(y, x)] += 1;
        }
    }

    vll ans(10, 0);
    for (auto elm : nuri) {
        ans[elm.snd] += 1;
    }
    ans[0] = (h - 2) * (w - 2);
    FOR (i, 1, 10) {
        ans[0] -= ans[i];
    }
    rep (i, 10) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}