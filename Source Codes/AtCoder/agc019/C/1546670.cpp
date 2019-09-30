#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

// Longest (Strictly) Increasing Sequence
class LIS{
public:
    vector<ll> S, L;
    LIS(vector<ll> S) : S(S) {}
    
    vector<ll> calc(){
        int len = 1; // length of LIS
        L.push_back(S[0]);
        rep(i, 1, S.size()){
            if (L[len - 1] < S[i]) {
                L.push_back(S[i]);
                len++;
            }
            else{
                int l = -1, r = len - 1;
                while (r - l > 1) {
                    int mid = (r + l) / 2;
                    if (L[mid] >= S[i]) {
                        r = mid;
                    }
                    else{
                        l = mid;
                    }
                }
                if(L[r] > S[i]) L[r] = S[i];
            }
        }
        return L;
    }
};
double pi = acos(-1.0);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    pair<ll, ll> S, G;
    cin >> S.first >> S.second >> G.first >> G.second;
    int N;
    cin >> N;
    vector<pair<ll, ll>> R(N);
    rep(i, N){
        cin >> R[i].first >> R[i].second;
    }
    
    if(S.first > G.first) {
        S.first *= -1, G.first *= -1;
        rep(i, N) R[i].first *= -1;
    }
    if(S.second > G.second){
        S.second *= -1, G.second *= -1;
        rep(i, N) R[i].second *= -1;
    }
    
    vector<ll> A;
    sort(all(R));
    for(auto r: R){
        if((r.first - S.first) * (r.first - G.first) <= 0 && (r.second - S.second) * (r.second - G.second) <= 0) {
            A.pb(r.second);
        }
    }
    
    vector<ll> L;
    if(A.size() > 0){
        LIS lis(A);
        L = lis.calc();
    }
    
    double ans = 0.0;
    int sz = (int)L.size();
    if(sz == min(abs(S.first - G.first), abs(S.second - G.second)) + 1) {
        sz--;
        ans = 10.0 * pi - 20.0;
    }
    ans += (5.0 * pi - 20.0) * sz;
    ans += 100.0 * (abs(S.first - G.first) + abs(S.second - G.second));
    
    output(ans, 15);
    
    return 0;
}