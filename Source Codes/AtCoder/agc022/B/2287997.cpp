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
ll gcd(ll a,ll b){
    if(a < b) swap(a,b);
    if(a % b == 0) return b;
    return gcd(b, a % b);

}

ll lcm(ll a,ll b){
    return a / gcd(a,b) * b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> ans(N);
    if (N % 8 == 0 || N % 8 == 7) {
        rep(i, 0, N) {
            ll mod = i % 4;
            ll div = i / 4;
            if (mod == 0) {
                ans[i] = 2LL + 6 * div;
            } else if (mod == 1) {
                ans[i] = 3LL + 6 * div;
            } else if (mod == 2) {
                ans[i] = 4LL + 6 * div;
            } else if (mod == 3) {
                ans[i] = 6LL + 6 * div;
            }
        }
        rep(i,0,N){
            cout << ans[i];
            if(i == N - 1){
                cout << endl;
            }else{
                cout << " ";
            }
        }
    }else{
        set<ll> ext;
        rep(i, 0, N-1) {
            ll mod = i % 4;
            ll div = i / 4;
            if (mod == 0) {
                ans[i] = 2LL + 6 * div;
            } else if (mod == 1) {
                ans[i] = 3LL + 6 * div;
            } else if (mod == 2) {
                ans[i] = 4LL + 6 * div;
            } else if (mod == 3) {
                ans[i] = 6LL + 6 * div;
            }
            ext.insert(ans[i]);
        }
        ll sum_v = 0LL;
        rep(i,0,N-1){
            sum_v += ans[i];
        }


//        ll add = 6 - (sum_v % 6);
//        if(add == 1) add += 6;
//        while(ext.find(add) != ext.end()){
//            add += 6;
//        }

        ll add = 2;
        while(true){
            if(ext.find(add) == ext.end() && gcd(add,sum_v) != 1 && gcd(sum_v + add,2) != 1 && gcd(sum_v + add,3) != 1){
                break;
            }
            add++;
//            if(add % 6 == 2){
//                add++;
//            }else if(add % 6 == 3){
//                add++;
//            }else if(add % 6 == 4){
//                add += 2;
//            }else if(add % 6 == 0){
//                add += 2;
//            }

        }

        ans[N-1] = add;

        rep(i,0,N){
            cout << ans[i];
            if(i == N - 1){
                cout << endl;
            }else{
                cout << " ";
            }
        }
    }
//    cout << ans[N-1] << endl;


    return 0;
}