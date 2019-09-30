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
    int X, Y, Z;
    int N;
    vector<ll> A, B, C;
    vector<vector<ll> > ABC;

    void input() {
        cin >> X >> Y >> Z;
        N = X + Y + Z;
        A.resize(X + Y + Z);
        B.resize(X + Y + Z);
        C.resize(X + Y + Z);
        rep(i, 0, N) {
            cin >> A[i] >> B[i] >> C[i];
            ABC.push_back(vector<ll>({A[i], B[i], C[i]}));
        }
    }

    void solve() {
        input();
        sort(all(ABC), [](vector<ll> a, vector<ll> b) {
            return -a[0] + a[1] < -b[0] + b[1];
        });

        vector<ll> AC(N + 1);
        vector<ll> BC(N + 1);

        for (int i = 0; i <= X - 1; ++i) AC[i] = -INFl;
        for (int i = 0; i <= Y - 1; ++i) BC[N - i] = -INFl;


        if (true) {
            priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<>> pq;
            ll Asum = 0ll;
            ll Csum = 0ll;
            for (int i = 0; i < X; ++i) {
                pq.emplace(ABC[i][0] - ABC[i][2], pair<ll, ll>(ABC[i][0], ABC[i][2]));
                Asum += ABC[i][0];
            }
            AC[X] = Asum;

            for (int i = X; i < N; ++i) {
                pq.emplace(ABC[i][0] - ABC[i][2], pair<ll, ll>(ABC[i][0], ABC[i][2]));
                Asum += ABC[i][0];

                auto top = pq.top();
                pq.pop();
                Asum -= top.second.first;
                Csum += top.second.second;


                AC[i + 1] = Asum + Csum;
            }

        }

        if (true) {
//            priority_queue<pair<ll, pair<ll, ll>>> pq;
            priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<>> pq;
            ll Bsum = 0ll;
            ll Csum = 0ll;
            for (int i = 0; i < Y; ++i) {
                int index = N - 1 - i;
                pq.emplace(ABC[index][1] - ABC[index][2], pair<ll, ll>(ABC[index][1], ABC[index][2]));
                Bsum += ABC[index][1];
            }
            BC[N - Y + 1] = Bsum;

            for (int i = N - Y - 1; i >= 0; --i) {

                pq.emplace(ABC[i][1] - ABC[i][2], pair<ll, ll>(ABC[i][1], ABC[i][2]));
                Bsum += ABC[i][1];

                auto top = pq.top();
                pq.pop();
                Bsum -= top.second.first;
                Csum += top.second.second;


                BC[i + 1] = Bsum + Csum;
            }

        }

        ll ans = 0ll;
        for (int i = 0; i < N; ++i) {
            ll tmp = AC[i] + BC[i + 1];
            chmax(ans, tmp);
        }

//        for(int i = 0; i < N; ++i){
//            cout << ABC[i][0] << " " << ABC[i][1] << " " << ABC[i][2] << endl;
//        }
//        cout << "---" << endl;
//
//        for (int i = 0; i <= N; ++i) {
//            if (AC[i] < -1000) cout << "IN ";
//            else cout << AC[i] << " ";
//        }
//        cout << endl;
//
//        for (int i = 0; i <= N; ++i) {
//            if (BC[i] < -1000) cout << "IN ";
//            else cout << BC[i] << " ";
//        }
//        cout << endl;


        cout << ans << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}