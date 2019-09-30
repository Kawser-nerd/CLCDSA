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
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007

//????????
template<typename T>
class Sum2d {
    vector<vector<T> > vv;
    unsigned xSize{};
    unsigned ySize{};
public:
    Sum2d(unsigned xSize, unsigned ySize) {
        vector<vector<T> > vv(xSize + 2, vector<T>(ySize + 2));
        this->vv = vv;
        this->xSize = xSize + 2;
        this->ySize = ySize + 2;
    }

    void add(int x, int y, T value) {
        x++;
        y++;
        this->vv[x][y] += value;
    }

    void set_sum() {
        for (int i = 0; i < xSize - 1; i++) {
            for (int j = 0; j < ySize; j++) {
                this->vv[i + 1][j] += vv[i][j];
            }
        }
        for (int i = 0; i < xSize; i++) {
            for (int j = 0; j < ySize - 1; j++) {
                this->vv[i][j + 1] += vv[i][j];
            }
        }
    }

    //[sx,tx],[sy,ty]???????ZE
    T calc(int sx, int sy, int tx, int ty) {
        tx++;
        ty++;
        return this->vv[tx][ty] + this->vv[sx][sy] - this->vv[tx][sy] - this->vv[sx][ty];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int> > S(N, vector<int>(M, 0));
    rep(i, 0, N) {
        rep(j, 0, M) {
            char tmp;
            cin >> tmp;
            if (tmp == '1') S[i][j] = 1;
        }
    }
    Sum2d<int> edge(2 * N - 1, 2 * M - 1), ver(2 * N - 1, 2 * M - 1);

    rep(i, 0, N) {
        rep(j, 0, M) {
            if (S[i][j]) {
                ver.add(2 * i, 2 * j, 1);
            }
        }
    }
    for (int i = 1; i < N; i++) {
        if (S[i - 1][0] == S[i][0] && S[i][0] == 1) {
            edge.add(2 * i - 1, 0, 1);
        }
    }
    for (int i = 1; i < M; i++) {
        if (S[0][i - 1] == S[0][i] && S[0][i] == 1) {
            edge.add(0, 2 * i - 1, 1);
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (S[i - 1][j] == S[i][j] && S[i][j] == 1) {
                edge.add(2 * i - 1, 2 * j, 1);
            }

            if (S[i][j - 1] == S[i][j] && S[i][j] == 1) {
                edge.add(2 * i, 2 * j - 1, 1);
            }
        }
    }

    bool debug = true;
    auto stat = [&]() {
        cout << "--" << endl;
//        rep(i, 0, N) {
//            rep(j, 0, M) {
//                cout << ver.calc(i, j, i, j) << " ";
//            }
//            cout << endl;
//        }
//        cout << "--" << endl;
//        rep(i, 0, N) {
//            rep(j, 0, M) {
//                cout << edge.calc(i, j, i, j) << " ";
//            }
//            cout << endl;
//        }
        rep(i, 0, N) {
            rep(j, 0, M) {
                cout << ver.calc(0, 0, i, j) << " ";
            }
            cout << endl;
        }
        cout << "--" << endl;
        rep(i, 0, N) {
            rep(j, 0, M) {
                cout << edge.calc(0, 0, i, j) << " ";
            }
            cout << endl;
        }
    };
    auto stat2 = [&]() {
        cout << "-stat2-" << endl;

        rep(i, 0, N) {
            rep(j, 0, M) {
                cout << ver.calc(i, j, i, j) << " ";
            }
            cout << endl;
        }
        cout << "--" << endl;
        rep(i, 0, N) {
            rep(j, 0, M) {
                cout << edge.calc(i, j, i, j) << " ";
            }
            cout << endl;
        }
    };
    if (debug) {
//        stat();
    }

    ver.set_sum();
    edge.set_sum();

    if (debug) {
//        stat();
//        stat2();
    }


    while (Q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;
        x1 *= 2;
        x2 *= 2;
        y1 *= 2;
        y2 *= 2;
//        cout << ver.calc(x1, y1, x2, y2) << " - " << edge.calc(x1, y1, x2, y2) << endl;
        cout << ver.calc(x1, y1, x2, y2) - edge.calc(x1, y1, x2, y2) << endl;
    }


    return 0;
}