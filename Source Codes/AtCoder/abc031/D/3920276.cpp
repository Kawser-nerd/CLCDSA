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

    vector<int> next(vector<int> vec) {
        int digit = 3;
        int n = vec.size();
        vec[0]++;
        for (int i = 0; i < n - 1; ++i) {
            if (vec[i] >= digit + 1) {
                vec[i] = 1;
                vec[i + 1]++;
            }
        }
        return vec;
    }

    void solve() {
        input();

        int K, N;
        cin >> K >> N;
        vector<string> v(N), w(N);
        rep(i, 0, N) {
            cin >> v[i] >> w[i];
        }

        vector<int> keta(K, 1);


        while (true) {
            if (keta == vector<int>({1, 2, 3, 3, 2, 1})) {
                int tree = 1 + 333;
            }
            //????
            vector<string> s(K);
            bool flag = true;
            for (int i = 0; i < N; ++i) {
                int numketa = 0;
                //????????????
                for (auto c : v[i]) {
                    numketa += keta[c - '1'];
                }
                if (numketa != w[i].size()) {
                    flag = false;
                    break;
                }

                int tapi = -1; //v[i]???????????
                int rest = keta[(v[i][++tapi] - '1')];
                string tmp = "";
                for (int j = 0; j < w[i].size(); ++j) {
                    tmp += w[i][j];
                    rest--;
                    if (rest == 0) {
                        if (s[v[i][tapi] - '1'] == "") {
                            s[v[i][tapi] - '1'] = tmp;
                        } else if (s[v[i][tapi] - '1'] != tmp) {
                            flag = false;
                        }
                        tmp = "";
                        if (tapi + 1 == v[i].size()) {
                            if (j + 1 != w[i].size()) {
                                flag = false;
                            }
                            break;
                        }
                        rest = keta[(v[i][++tapi] - '1')];
                    }
                }
            }


            if (flag) {
                for (auto str : s) {
                    cout << str << endl;
                }
                return;
            }


            keta = next(keta);
        }


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}