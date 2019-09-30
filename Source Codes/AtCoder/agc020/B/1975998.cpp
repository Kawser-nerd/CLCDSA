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
#define INF (1 << 30)
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
    vector<ll> A(N+1),l(N+1),h(N+1);

    rep(i,1,N+1){
        cin >> A[i];
    }

    l[N] = h[N] = 2;

//    if(A[N] > 2){
//        cout << -1 << endl;
//        return 0;
//    }

    for(int i = N; i > 0; i--){
        if(h[i] < A[i]){
            cout << -1 << endl;
            return 0;
        }

        ll low = l[i] / A[i] * A[i];
        if(low < l[i]) low += A[i];
        ll high = h[i] / A[i] * A[i];

        if(low > high){
            cout << -1 << endl;
            return 0;
        }

        if(low < l[i] || low > h[i]){
            cout << -1 << endl;
            return 0;
        }
        if(high < l[i] || high > h[i]){
            cout << -1 << endl;
            return 0;
        }

        l[i-1] = low;
        h[i-1] = high + (A[i] - 1);
    }


    cout << l[0] << " " << h[0] << endl;


    return 0;
}