#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//????????
int R, C, N;

bool line(int x, int y) {
    return x == 0 || x == R || y == 0 || y == C;
}

int check(int x1, int y1, int x2, int y2) {
//    if (x1 != 0 && x1 != R) return false;
//    if (y1 != 0 && y1 != C) return false;
//    if (x2 != 0 && x2 != R) return false;
//    if (y2 != 0 && y2 != C) return false;
//    return true;
    return line(x1, y1) && line(x2, y2);
}

int shougen(int x, int y) {
    if (x == 0) return 0;
    if (y == C) return 1;
    if (x == R) return 2;
    if (y == 0) return 3;
    cerr << "error" << endl;
    return -1;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> R >> C >> N;

//    vector<pair<int, int>, int> vp;
    vector<pair<pair<int, int>, int>> vp;
    rep(i, 0, N) {
        int x1;
        int y1;
        int x2;
        int y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (check(x1, y1, x2, y2)) {
            pair<pair<int, int>, int> xy1(pair<int, int>(x1, y1), i);
            pair<pair<int, int>, int> xy2(pair<int, int>(x2, y2), i);
            vp.push_back(xy1);
            vp.push_back(xy2);
        }
    }

    sort(all(vp), [](pair<pair<int, int>, int> xy1, pair<pair<int, int>, int> xy2) {
        int x1 = xy1.first.first;
        int y1 = xy1.first.second;
        int x2 = xy2.first.first;
        int y2 = xy2.first.second;
        int shou1 = shougen(x1, y1);
        int shou2 = shougen(x2, y2);
        if (shou1 < shou2) return true;
        if (shou1 > shou2) return false;

        if (shou1 == 0) {
            return y1 < y2;
        }
        if (shou1 == 1) {
            return x1 < x2;
        }
        if (shou1 == 2) {
            return y1 > y2;
        }
        if (shou1 == 3) {
            return x1 > x2;
        }
        return true;
    });

    vector<int> v;
    for (auto e : vp) {
        v.push_back(e.second);
    }

    stack<int> st;
    for (auto e : v) {
        if (st.empty()) {
            st.push(e);
        } else if (st.top() == e) {
            st.pop();
        } else {
            st.push(e);
        }
    }

    if (st.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}