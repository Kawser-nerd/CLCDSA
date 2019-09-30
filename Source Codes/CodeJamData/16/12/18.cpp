#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int ar[2501];

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    FOR(ts, 1, T+1){
        int n; cin >> n;
        set0(ar);
        REP(i, 2*n-1){
            REP(j, n){
                int x; cin >> x;
                ar[x] ^= 1;
            }
        }
        cout << "Case #" << ts << ":";
        int cnt = 0;
        FOR(i, 1, 2501){
            if(ar[i]) {
                cout << " " << i;
                cnt++;
            }
        }
        cout << endl;
        cerr << cnt << " " << n << endl;
        assert(cnt == n);
    }
}
