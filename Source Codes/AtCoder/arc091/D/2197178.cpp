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

ll grandy(ll N,ll K){
    if(N < K){
        return 0;
    }
    if(N % K == 0){
        return N / K;
    }else{
//        if(N / K == 0){
//            return grandy(K,K)
//        }
//        return grandy(N - N/K - 1,K);
        ll div = N / K + 1;
        ll target = N / K * K;
        ll nextN = N;
        nextN -= (N - target) / div * div;
        if(nextN > target) nextN -= div;
        return grandy(nextN,K);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
//    if(true){
//        cout << grandy(2147,1000);
//        return 0;
//    }

    int N;
    cin >> N;
    ll nim = 0;
    rep(i,0,N){
        ll A,B;
        cin >> A >> B;
        nim ^= grandy(A,B);
    }
    if(nim == 0){
        cout << "Aoki" << endl;
    }else{
        cout << "Takahashi" << endl;
    }



    return 0;
}