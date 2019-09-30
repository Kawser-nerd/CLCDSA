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

int digits( int n ) {
    int ans = 0;
    while ( n > 0 ) {
        n /= 10;
        ans += 1;
    }
    return ans;
}

int po10( int n ) {
    int ans = 1;
    rep (i, n) {
        ans *= 10;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vi d(k);
    rep (i, k) { cin >> d[i]; }
    sort(all(d));
    vi able;
    rep (i, 10) {
        if ( lower_bound(all(d), i) == upper_bound(all(d), i) ) {
            able.eb(i);
        }
    }
    int ds = digits(n);
    int samed = 0;
    rep (i, ds) {
        samed += *(end(able)-1) * po10(i);
    }
    if ( samed < n ) {
        int bigd = 0;
        rep (i, ds+1) {
            bigd += *begin(able) * po10(i);
        }
        if ( *begin(able) == 0 ) {
            bigd = *(begin(able)+1) * po10(ds);
        }
        printf("%d\n", bigd);
        return 0;
    }

//    vi nd;
//    int n_ = n;
//    rep (i, ds) {
//        nd.eb(n_ % 10);
//        n_ /= 10;
//    }
//    reverse(all(nd));
//    int ans = 0;

    FOR (i, n, 10000) {
        int i_ = i;
        int dsi = digits(i_);
        bool flag = true;
        rep (j, dsi) {
            int m = (i_ % 10);
            if ( lower_bound(all(able), m) == upper_bound(all(able), m) ) {
                flag = false;
                break;
            }
            i_ /= 10;
        }
        if ( flag ) {
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}