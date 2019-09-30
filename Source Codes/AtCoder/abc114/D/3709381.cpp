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
    int N;
    vector<int> primes;

    void input() {
        cin >> N;
        for (int i = 2; i < N; ++i) {
            bool flag = true;
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) flag = false;
            }
            if (flag) primes.push_back(i);
        }
    }

    int compute(int num, int div) {
        int ret = 0;
        while (num > 0) {
            ret += num / div;
            num /= div;
        }
        return ret;
    }

    void solve() {
        input();
        int ans = 0;

        for (auto ei: primes) {
            if (compute(N, ei) >= 74) ans++;
            for (auto treeone: primes) {
                if (ei == treeone) continue;
                if (compute(N, ei) >= 2 && compute(N, treeone) >= 24) {
                    ans++;
                }

                if (compute(N, ei) >= 4 && compute(N, treeone) >= 14) {
                    ans++;
                }

                for (auto tapione: primes) {
                    if (ei != tapione && treeone < tapione && compute(N, ei) >= 2 && compute(N, treeone) >= 4 &&
                        compute(N, tapione) >= 4) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}