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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;
    vector<vector<int> > vv(100, vector<int>(100));
    int big = max(A, B);
    int small = min(A, B);
    [&] {

        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                int x = i * 4;
                int y = j * 4;
                for (int dx = 0; dx < 3; dx++) {
                    for (int dy = 0; dy < 3; dy++) {
                        vv[x + dx][y + dy] = 1;

                    }
                }
                if (small > 1) {
                    small--;
                    vv[x + 1][y + 1] = 0;
                }
                big--;
                if (big == 0) return;
            }
        }
    }();

    cout << 100 << " " << 100 << endl;
    if (A < B) {
        rep(i, 0, 100) {
            rep(j, 0, 100) {
                if (vv[i][j] == 0) cout << ".";
                else cout << "#";
            }
            cout << endl;
        }
    } else {
        rep(i, 0, 100) {
            rep(j, 0, 100) {
                if (vv[i][j] == 0) cout << "#";
                else cout << ".";
            }
            cout << endl;
        }
    }


    return 0;
}