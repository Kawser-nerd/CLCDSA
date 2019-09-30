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

    int N, M;
    cin >> N >> M;
    vector<vector<int> > G(N);
    vector<bool> used(N, false);
    rep(i, 0, M) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    int cur = 0;
    vector<int> anss;
    while (true) {
        anss.push_back(cur);
        used[cur] = true;
        int next = -1;
        for (auto e : G[cur]) {
            if (!used[e]) {
                next = e;
                break;
            }
        }
        if (next == -1) break;
        cur = next;
    }
    cur = anss[0];
    reverse(all(anss));
    while (true) {
        if(!used[cur])
        anss.push_back(cur);
        used[cur] = true;
        int next = -1;
        for (auto e : G[cur]) {
            if (!used[e]) {
                next = e;
                break;
            }
        }
        if (next == -1) break;
        cur = next;
    }


    cout << anss.size() << endl;
    rep(i, 0, anss.size()) {
        cout << anss[i] + 1;
        if (i == anss.size() - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }


    return 0;
}