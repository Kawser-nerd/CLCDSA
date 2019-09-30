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
//#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
//#define EXIST(s, e) ((s).find(e)!=(s).end())
//#define SORT(c) sort(begin(c),end(c))
//#define pb emplace_back
//#define MP make_pair
//#define SZ(a) int((a).size())

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

    int N, C;
    cin >> N >> C;

    vector<vector<int> > D(C, vector<int>(C));//???
    vector<vector<int> > c(N, vector<int>(N));//grid

    rep(i,0,C){
        rep(j,0,C){
            cin >> D[i][j];
        }
    }

    rep(i,0,N){
        rep(j,0,N){
            cin >> c[i][j];
        }
    }
    vector<vector<int>> gr(3, vector<int>(C + 1));

    rep(i, 0, N) {
        rep(j, 0, N) {
            gr[(i + j) % 3][c[i][j]]++;
        }
    }


    int ans = INF;
    rep(c1, 0, C) {
        rep(c2, 0, C) {
            rep(c3, 0, C) {
                if (c1 == c2 || c2 == c3 || c1 == c3) continue;
                int tmp = 0;
                rep(i, 0, C) {
                    tmp += gr[0][i + 1] * D[i][c1];
                }
                rep(i, 0, C) {
                    tmp += gr[1][i + 1] * D[i][c2];
                }
                rep(i, 0, C) {
                    tmp += gr[2][i + 1] * D[i][c3];
                }
                ans = min(ans,tmp);
            }
        }
    }

    cout << ans << endl;


    return 0;
}