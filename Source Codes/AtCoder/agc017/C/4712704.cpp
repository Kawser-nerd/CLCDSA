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
        int N, M;
        cin >> N >> M;
        vector<int> A(N);
        vector<int> B(N + 1); //?????
        vector<int> C(N); // [i, i + 1]???????
        int blank = 0;  //?????
        rep(i, 0, N) {
            cin >> A[i];
            B[A[i]]++;
            if (A[i] - B[A[i]] >= 0)
                C[A[i] - B[A[i]]]++;
        }
        for (int i = 0; i < N; ++i) blank += !C[i];

        for (int i = 0; i < M; ++i) {
            int x, y;
            cin >> x >> y;
            x--;
            int prev = A[x]; // ??????
            A[x] = y;

            //prev???????
            if (prev - B[prev] >= 0) {
                C[prev - B[prev]]--;
                if (C[prev - B[prev]] == 0) {
                    blank++;
                }
            }
            B[prev]--;

            //y???????
            B[y]++;
            if (y - B[y] >= 0) {
                C[y - B[y]]++;
                if (C[y - B[y]] == 1) {
                    blank--;
                }
            }

            cout << blank << endl;
        }


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}