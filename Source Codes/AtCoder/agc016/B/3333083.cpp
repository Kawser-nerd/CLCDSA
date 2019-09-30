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

/*
 * n????k???????????????
 * */
bool same(int n, int k) {
    if (k <= 0) return false;
    if (n - 1 == k) return true;
    return n / 2 >= k;
}

/*
 * ????????????
 */
bool same2(int n, int k) {
    if (k <= 0) return false;
    return n / 2 >= k;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> a(N);
    rep(i, 0, N) cin >> a[i];

    sort(all(a));
    if (a.back() - a.front() > 1) {
        cout << "No" << endl;
        return 0;
    }

    int x = a.front();
    int y = a.back();

    int z = count(all(a), x);

    if (x == y) {
        if (same(N, y)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if (same2(N - z, y - z)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }


    return 0;
}