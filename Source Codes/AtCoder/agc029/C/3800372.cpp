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
    int musi = 100;
    vector<ll> A;

    void input() {

    }

    bool check(ll num) {
        //num?????????
        vector<ll> digit(musi);
        int n = A.size();
        for (int i = 1; i < n; ++i) {
            if (A[i - 1] >= A[i]) {
                //A[i]??????(vec??????)????
                for (int j = A[i] + 1; j < musi; ++j) {
                    digit[j] = 0ll;
                }
                digit[A[i]]++;
                for (int j = A[i]; j > 1; --j) {
                    if (digit[j] >= num) {
                        digit[j] -= num;
                        digit[j - 1]++;
                    }
                }
                if (digit[1] >= num) return false;
            }
        }
        return digit[1] < num;
    }

    void solve() {
        input();
        int N;
        cin >> N;
        vector<ll> v(N);
        rep(i, 0, N) cin >> v[i];
        bool flag = true;
        for (int i = 0; i < N - 1; ++i) {
            if (v[i] >= v[i + 1]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << 1 << endl;
            return;
        }


        rep(i, 0, N) {
            int tmp = v[i];
            if (tmp < musi) {
                A.push_back(tmp);
            }
        }

        ll ng = 1;
        ll ok = (ll) 1e6;
        while (ok - ng > 1) {
            ll mid = (ok + ng) / 2;
            if (check(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        check(2);

        cout << ok << endl;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}