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

    int N;
    cin >> N;
    string S;
    cin >> S;
    reverse(S.begin() + N,S.begin() + 2 * N);

    map<pair<string,string>, ll> mp;

    for(int i = 0;  i < 1 << N; i++){
        string red,blue;
        for(int bit = 0; bit < N; bit++){
            if(i >> bit & 1){
                red += S[bit];
            }else{
                blue += S[bit];
            }
        }
        mp[make_pair(red,blue)]++;
    }

    ll ans = 0ll;
    for(int i = 0;  i < 1 << N; i++){
        string red,blue;
        for(int bit = 0; bit < N; bit++){
            if(i >> bit & 1){
                blue += S[bit + N];
            }else{
                red += S[bit + N];
            }
        }
        ll tmp = mp[make_pair(blue,red)];
        ans += tmp;
    }

    cout << ans << endl;


    return 0;
}