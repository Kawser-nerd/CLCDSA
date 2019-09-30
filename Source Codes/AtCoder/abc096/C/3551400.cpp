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
    vector<vector<char> > vvc;

    void input() {
        cin >> H >> W;
        vvc.resize(H + 2, vector<char>(W + 2));
        rep(i, 1, H + 1) {
            rep(j, 1, W + 1) {
                cin >> vvc[i][j];
            }
        }

    }

    void solve() {
        input();
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                if (vvc[i][j] == '#') {
                    bool flag = false;
                    int di[] = {1, 0, -1, 0};
                    int dj[] = {0, 1, 0, -1};

                    rep(k, 0, 4) {
                        int I = i + di[k];
                        int J = j + dj[k];
                        if(vvc[I][J] == '#'){
                            flag = true;
                        }
                    }
                    if(!flag){
                        cout << "No" << endl;
                        exit(0);
                    }
                }
            }
        }
        cout << "Yes" << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}