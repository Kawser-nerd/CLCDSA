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

    int N;
    cin >> N;

    vector<bool> eraf(N + 1, true);
    eraf[0] = eraf[1] = false;
    for (int i = 2; i <= N; i++) {
        if (eraf[i]) {
            for (int j = i * 2; j <= N; j += i) {
                eraf[j] = false;
            }
        }
    }
    vector<int> prime;
    rep(i, 0, N + 1) {
        if (eraf[i]) prime.push_back(i);
    }
    vector<int> num(prime.size(), 1);
    for (int i = 2; i <= N; i++) {
        int tmp = i;

        for (int j = 0; tmp != 1;) {
            if (tmp % prime[j] == 0) {
                num[j]++;
                tmp /= prime[j];
            }else{
                j++;
            }
        }
    }

    ll ans = 1;
    rep(i,0,num.size()){
        ans *= num[i];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}