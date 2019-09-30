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

vector<vector<int> > H;
vector<int> colors;

bool paint(int v, int c) {
    colors[v] = c;
    for (int i = 0; i < H[v].size(); i++) {
        if (H[v][i]) {
            if (colors[i] == c) return false;
            if (colors[i] == 0 && !paint(i, -c)) return false;
        }
    }

    return true;
}

pair<int, int> dfs(int v) {
    pair<int, int> ret(0, 0);
    if (colors[v] == 1) ret.first++;
    else if (colors[v] == -1) ret.second++;
    else if (colors[v] == 0) return ret;
    colors[v] = 0;
    for (int i = 0; i < H.size(); i++) {
        if (H[v][i]) {
            pair<int, int> tmp = dfs(i);
            ret.first += tmp.first;
            ret.second += tmp.second;
        }
    }

    return ret;
}

int func(int num) {
    return num * (num - 1) / 2;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > G(N, vector<int>(N));
    H = vector<vector<int> >(N, vector<int>(N));
    colors.resize(N, 0);

    rep(i, 0, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b] = G[b][a] = 1;
    }

    rep(i, 0, N) {
        rep(j, 0, N) {
            H[i][j] = !G[i][j];
            if (i == j) H[i][j] = 0;
        }
    }

    rep(i, 0, N) {
        if (colors[i] == 0) {
            if (!paint(i, 1)) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vector<pair<int, int> > pairs;
    rep(i, 0, N) {
        if (colors[i] != 0) {
            pair<int, int> tmp = dfs(i);
            pairs.push_back(tmp);
        }
    }

    vector<int> dp(N + 1);
    dp[0] = 1;
//    dp[pairs[0].first] = dp[pairs[0].second] = 1;
    rep(i, 0, pairs.size()) {
        vector<int> tmp(N + 1);
        //pairs[i]????????
        for (int j = N; j >= 0; j--) {
            if (dp[j] && j + pairs[i].first <= N) tmp[j + pairs[i].first] = 1;
            if (dp[j] && j + pairs[i].second <= N) tmp[j + pairs[i].second] = 1;
        }
        dp = tmp;
    }

    int min_k = -1;
    int min_v = INF;

    for (int i = 0; i <= N; i++) {
        if (dp[i]) {
            int a = i;
            int b = N - i;
            int tmp = func(a) + func(b);
            if (tmp < min_v) {
                min_k = a;
                min_v = tmp;
            }
        }
    }

    cout << min_v << endl;


    return 0;
}