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
auto getPrimes(int lim) {
    vector<bool> flags(lim + 1, true);
    flags[0] = flags[1] = false;

    for (int i = 2; i <= lim; i++) {
        if (flags[i]) {
            for (int j = 2 * i; j <= lim; j += i) {
                flags[j] = false;
            }
        }
    }

    vector<int> primes;

    for (int i = 0; i <= lim; i++) {
        if (flags[i]) {
            primes.push_back(i);
        }
    }

    return primes;

}
class Solve{
public:
    int N;
    void input(){
        cin >> N;

    }
    void solve(){
        input();
        vector<int> primes = getPrimes(334334);
        vector<int> ans;
        for(auto e : primes){
            if(ans.size() >= N){
                break;
            }
            if(e % 5 == 1){
                ans.push_back(e);
            }
        }
        for(int i = 0; i < ans.size(); ++i){
            cout << ans[i];
            if(i == ans.size() - 1){
                cout << endl;
            }else{
                cout << " ";
            }
        }
    }

};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}