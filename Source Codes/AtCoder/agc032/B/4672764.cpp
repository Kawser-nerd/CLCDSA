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
#include <cstring>

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

    void solve() {
        input();
        int N;
        cin >> N;
        int S = 1 + N;
        if (N % 2 == 1) S = N;
        vector<pair<int, int> > ans;
        for (int i = 1; i <= N; ++i) {
            int musi = S - i;
            for (int j = i + 1; j <= N; ++j) {
                if (j != musi) ans.emplace_back(i, j);
            }
        }

        cout << ans.size() << endl;
        for (auto e : ans) {
            cout << e.first << " " << e.second << endl;
        }

        //test
//        vector<int> sum(N + 1);
//        for (auto e : ans) {
//            sum[e.first] += sum[e.second];
//            sum[e.second] += sum[e.first];
//        }
//
//        for (int i = 0; i < N; ++i) {
//            if (sum[i] != sum[i + 1]) {
//                exit(-1);
//                cerr << "err" << endl;
//            }
//        }


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}