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

    int N;
    cin >> N;

    vector<pair<char, int> > vpi;
    for (int i = 0; i < 2 * N; i++) {
        char c;
        int a;
        cin >> c >> a;
        vpi.emplace_back(c, a);
    }

    vector<vector<int> > costw(N + 2, vector<int>(N + 2, 0));
    vector<vector<int> > costb(N + 2, vector<int>(N + 2, 0));

    for (int i = 0; i < 2 * N; i++) {
        int sum_w = 0;
        vector<int> ruib(N + 1);

        if (vpi[i].first == 'B') continue;
        int key = vpi[i].second;

        for (int j = i + 1; j < 2 * N; j++) {
            if (vpi[j].first == 'W') {
                if (vpi[j].second < vpi[i].second) {
                    sum_w++;
                }
            } else {
                ruib[vpi[j].second]++;
            }
        }

        for (int j = 0; j < N; j++) {
            ruib[j + 1] += ruib[j];
        }

        for (int j = 0; j <= N; j++) {
            costw[key][j] = ruib[j] + sum_w;//
        }
    }
    for (int i = 0; i < 2 * N; i++) {
        int sum_b = 0;
        vector<int> ruiw(N + 1);

//
        if (vpi[i].first == 'W') continue;
        int key = vpi[i].second;

        for (int j = i + 1; j < 2 * N; j++) {
            if (vpi[j].first == 'B') {
                if (vpi[j].second < vpi[i].second) {
                    sum_b++;
                }
            } else {
                ruiw[vpi[j].second]++;
            }
        }
//
        for (int j = 0; j < N; j++) {
            ruiw[j + 1] += ruiw[j];
        }
//
        for (int j = 0; j <= N; j++) {
            costb[j][key] = ruiw[j] + sum_b;//
        }
    }

    vector<vector<int> > dp(N + 2, vector<int>(N + 2, 0));//i:?, j:?

//    dp[0][0] = 0;
//    dp[1][0] = 1;
//    dp[0][1] = 1;

    for (int i = 1; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] + costw[i][0];
    }

    for (int i = 1; i <= N; i++) {
        dp[0][i] = dp[0][i - 1] + costb[0][i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
//            int val1 = dp[i - 1][j] + costw[i - 1][j];
//            int val2 = dp[i][j - 1] + costb[i][j - 1];
            int val1 = dp[i - 1][j] + costw[i][j];
            int val2 = dp[i][j - 1] + costb[i][j];
            dp[i][j] = min(val1, val2);
        }
    }

    cout << dp[N][N] << endl;

//    for(int i = 0; i <= N; i++){
//        for(int j = 0; j <= N; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}