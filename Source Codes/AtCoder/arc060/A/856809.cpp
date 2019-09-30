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
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<i_i, int> p_i;
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

// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        s << v[i]; if (i < len - 1) s << "\t";
    }
    return s;
}

// cout 2-dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
    int len = vv.size();
    for (int i = 0; i < len; ++i) {
        s << vv[i] << endl;
    }
    return s;
}

ll po2(int x) {
    if ( x == 1 ) {
        return 2;
    } else if ( x == 0 ) {
        return 1;
    }
    ll tmp = po2(x / 2);
    tmp *= tmp;
    if ( x % 2 == 0 ) {
        return tmp;
    } else {
        return tmp * 2;
    }
}

int main() {
    int n, a;
    cin >> n >> a;
    vi x(n);
    rep (i, n) {
        cin >> x[i];
        x[i] -= a;
    }
    sort(all(x));

    auto mark1 = lower_bound(all(x), 0);
    auto mark2 = upper_bound(all(x), 0);
    int be = *begin(x) * *(end(x)-1);
    ll base = po2(mark2 - mark1);
    if ( be > 0 ) {
        printf("0\n");
        return 0;
    } else if ( be == 0 ) {
        printf("%lld\n", base-1);
        return 0;
    }

    vvi part(2, vi());
    for (int i = 0; x[i] < 0; ++i) {
        part[0].eb(-x[i]);
    }
    sort(all(part[0]));
    for (int i = mark2 - begin(x); i < n; ++i) {
        part[1].eb(x[i]);
    }
//    int lenl = part[0].size();
//    int lenr = part[1].size();
//    int suml = 0;
//    int sumr = 0;
//    rep (i, lenl) {
//        suml += part[0][i];
//    }
//    rep (i, lenr) {
//        sumr += part[1][i];
//    }
//    int small;
//    if ( suml > sumr ) {
//        small = 1;
//    } else {
//        small = 0;
//    }

    int ma = 2501;
    vvll p(2, vll(ma, 0));
    p[0][0] = p[1][0] = 1;
    int currentmax = 0;
    rep (i, 2) {
        currentmax = 0;
        rep (j, (int)part[i].size()) {
            vll tmp(ma, 0);
            rep (k, currentmax+1) {
                tmp[part[i][j]+k] += p[i][k];
            }
            currentmax += part[i][j];
            rep (k, ma) {
                p[i][k] += tmp[k];
            }
        }
    }
    ll ans = 0;
    rep (i, ma) {
        ans += p[0][i] * p[1][i];
    }
    printf("%lld\n", ans * base - 1);

    return 0;
}