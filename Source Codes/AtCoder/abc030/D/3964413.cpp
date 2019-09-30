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
        int N;
        cin >> N;
        int a;
        cin >> a;

        string k;
        cin >> k;


        vector<vector<int> > G(N);
        rep(i, 0, N) {
            int b;
            cin >> b;
            b--;
            G[i].push_back(b);
        }

        if (k.size() <= 5) {
            //???????????
            int K = stoi(k);
            int pt = a - 1;
            while (K--) {
                pt = G[pt][0];
            }
            cout << pt + 1 << endl;
            return;
        }

        //k?1e6??

        //?????????
        int loopStart = -1;
        set<int> used;
        int muda = 0; //????????
        int pt = a - 1;
        while (true) {
            if (used.count(pt)) {
                loopStart = pt;
                break;
            } else {
                muda++;
                used.insert(pt);
                pt = G[pt][0];
            }
        }

        //????????
        used = set<int>();
        vector<int> vec; //?????
        int loopPeriod = 0;
        pt = loopStart;
        while (true) {
            if (used.count(pt)) {
                break;
            } else {
                loopPeriod++;
                vec.push_back(pt);
                used.insert(pt);
                pt = G[pt][0];
            }
        }

        ll amari = 0ll;
        for (char c : k) {
            amari *= 10ll;
            int num = c - '0';
            amari += num;
            amari %= loopPeriod;
        }
        amari -= muda;
        amari %= loopPeriod;
        if (amari < 0) amari += loopPeriod;

        int ans = vec[amari] + 1;

        cout << ans << endl;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}