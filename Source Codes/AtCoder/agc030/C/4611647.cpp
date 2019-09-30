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
    int K;

    void input() {
        cin >> K;
    }

    void ki() {
        if (K == 1) {
            cout << 1 << endl << 1 << endl;
            return;
        }
        int m = (K / 4 + 1) * 2;
        vector<vector<int> > ans(m, vector<int>(m));
        cout << m << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = (i + j) % m + m * (j % 2 == 1);
//                if (ans[i][j] == 2 * m - 1) ans[i][j] = m - 1;
                if (ans[i][j] >= K) ans[i][j] -= m;
                cout << ans[i][j] + 1 << " ";
            }
            cout << endl;
        }
    }

    void gu() {
        int m = K / 2;
        if(K == 2){
            cout << 2 << endl << 2 << " " << 1 << endl << 1 << " " << 2 << endl;
            return;
        }
        vector<vector<int>> ans(m, vector<int>(m));
        cout << m << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = i % m + m * (j % 2 == 1);
                cout << ans[i][j] + 1 << " ";
            }
            cout << endl;
        }
    }

    void solve() {
        input();
//        if (K % 2) ki();
//        else gu();
        if(K == 2 || K % 4 == 0) gu();
        else ki();

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}