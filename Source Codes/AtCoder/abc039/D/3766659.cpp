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
    int H, W;
    vector<string> S;

    void input() {
        cin >> H >> W;
        S.resize(H);
        rep(i, 0, H) cin >> S[i];

    }

    bool range(int i, int j) {
        return i >= 0 && i < H && j >= 0 && j < W;
    }

    void solve() {
        input();
        vector<vector<char>> T(H, vector<char>(W, '#'));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (range(i + di, j + dj) && S[i + di][j + dj] == '.') {
                            T[i][j] = '.';
                        }
                    }
                }
            }
        }

        vector<vector<char> > U(H, vector<char>(W, '.'));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (range(i + di, j + dj) && T[i + di][j + dj] == '#') {
                            U[i][j] = '#';
                        }
                    }
                }
            }
        }

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (S[i][j] != U[i][j]) {
                    cout << "impossible" << endl;
                    return;
                }
            }
        }

        cout << "possible" << endl;

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cout << T[i][j];
            }
            cout << endl;
        }


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}