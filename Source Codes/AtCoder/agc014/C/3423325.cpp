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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, K;
    cin >> H >> W >> K;
    vector<string> A;
    rep(i, 0, H) {
        string s;
        cin >> s;
        A.push_back(s);
    }

    int sx, sy;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    using Pxy = pair<int, int>; //??
    using V = pair<Pxy, int>; //????


    set<Pxy> grids; //??????????
    set<Pxy> used; // ????
    queue<V> que;
    que.push(V(Pxy(sx, sy), 0));
    used.emplace(sx, sy);

    while (!que.empty()) {
        V top = que.front();
        que.pop();
        if (top.second <= K) {
            grids.insert(top.first);
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, -1, 0, 1};
            for (int k = 0; k < 4; ++k) {
                int h = top.first.first + dx[k];
                int w = top.first.second + dy[k];

                if (h >= 0 && h < H && w >= 0 && w < W) {
                    if (A[h][w] == '.' && !used.count(Pxy(h, w))) {
                        que.push(V(Pxy(h, w), top.second + 1));
                        used.insert(Pxy(h, w));
                    }
                }
            }

        }
    }

    int ans = INF;
    for (auto e : grids) {
        int h = e.first;
        int w = e.second;

        vector<int> kouho;
        kouho.push_back(h);
        kouho.push_back(H - 1 - h);
        kouho.push_back(w);
        kouho.push_back(W - 1 - w);
        sort(all(kouho));
        int dist = kouho[0] / K + (kouho[0] % K != 0) + 1;

        chmin(ans, dist);
    }

    cout << ans << endl;

    return 0;
}