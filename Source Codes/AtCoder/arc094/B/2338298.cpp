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
ll cal(ll a){
    ll ret = (ll)sqrt(a);
    if(ret * ret == a) ret--;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;
    while(Q--){
        ll a,b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        ll ans = 0ll;
        if(a == b){
            ans = 2 * (a - 1);
        }else if(a + 1 == b){
            ans = 2 * (a - 1);
        }else{
//            ans = 2 * (a - 1) + (b - a) - 1;
            ll C = cal(a * b);
            ll D = a * b / C;
            if(C * D != a * b){
                if(D == C){
                    ans = 2*C - 2;
                }else{
                    ans = 2*C - 1;
                }
            }else{
                if(D - C > 1){
                    ans = 2 * C - 1;
                }else if(D == C + 1){
                    ans = 2 * C - 2;
                }else if(D == C){
                    ans = 2 * C - 2;
                    if(a < C){
                        ans--;
                    }
                }
            }
        }
        cout << ans << endl;
    }


    return 0;
}