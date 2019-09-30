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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    ll X = N + 1;
    ll val = 1ll;
    deque<int> dq;

    int len = 0;
    for (len = 0; X >> len > 0; len++);

//    for(int i = 0; i < len; ++i){
//
//    }

    int cnt = 1;
    for (int i = len - 1; i >= 0; --i) {
        if (i == 0) {
            if ((X >> i & 1) != (val & 1)) {
                val += 1ll;
                dq.push_front(cnt++);
            }
            break;
        }
        if ((X >> i & 1) == (val & 1)) {
            val <<= 1;
            dq.push_back(cnt++);
        } else {
            val += 1ll;
            dq.push_front(cnt++);

            val <<= 1;
            dq.push_back(cnt++);
        }
    }

    vector<int> ans;
    rep(i, 1, cnt) ans.push_back(i);
    for (auto e : dq) ans.push_back(e);

    cout << ans.size() << endl;
    rep(i, 0, ans.size()) {
        cout << ans[i];
        if (i == ans.size() - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }


    return 0;
}