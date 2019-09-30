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

    void solve() {
        input();
        int N, M;
        cin >> N >> M;
        int X, Y;
        cin >> X >> Y;

        vector<int> a(N), b(M);
        rep(i, 0, N) cin >> a[i];
        rep(i, 0, M) cin >> b[i];

        int pa = 0;
        int pb = 0;

        int cnt = 0;
        int time = 0;
        int turn = 0;
        while (pa < N && pb < M) {
            if (turn == 0) {
                while (pa < N && a[pa] < time) {
                    pa++;
                }
                if (pa < N) {
                    turn = 1;
                    cnt++;
                    time = a[pa] + X;
                }
            } else {
                while (pb < M && b[pb] < time) {
                    pb++;
                }
                if (pb < M) {
                    turn = 0;
                    cnt++;
                    time = b[pb] + Y;
                }
            }
        }

        int ans = cnt / 2;

        cout << ans << endl;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}