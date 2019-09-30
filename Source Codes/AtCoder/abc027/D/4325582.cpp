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
class Solve {
public:
    void input() {

    }

    vector<int> parse(string s) {
        s += 'M';
        vector<int> ret;
        int i = 0;
        while (s[i] != 'M') {
            i++;
        }

        int val = 0;
        i++;
        for (; i < s.size(); ++i) {
            if (s[i] == 'M') {
                ret.push_back(val);
                val = 0;
            } else if (s[i] == '+') {
                val++;
            } else if (s[i] == '-') {
                val--;
            }
        }

        return ret;
    }

    void solve() {
        input();
        string s;
        cin >> s;

        auto v = parse(s);
        size_t n = v.size();
        vector<int> rui(n);
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) rui[i] = v[i];
            else rui[i] = rui[i + 1] + v[i];
        }

        sort(all(rui));
        ll ans = 0ll;
        for (size_t i = 0; i < n / 2; ++i) {
            ans -= rui[i];
        }
        for (size_t i = n / 2; i < n; ++i) {
            ans += rui[i];
        }
        cout << ans << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}